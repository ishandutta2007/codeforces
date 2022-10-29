import qualified Data.List as List
import qualified Data.Sequence as Sequence

type Edge = (Int, Int)
type Graph = Sequence.Seq [Edge]
type Paths = Sequence.Seq Int
type DijkstraHeap = MinHeap (Int, Int, Int)

data MinHeap a = HeapEmpty | HeapNode Int a (MinHeap a) (MinHeap a)

rank :: MinHeap a -> Int
rank HeapEmpty = 0
rank (HeapNode x _ _ _) = x

singleton :: a -> MinHeap a
singleton x = HeapNode 1 x HeapEmpty HeapEmpty

merge :: (Ord a) => MinHeap a -> MinHeap a -> MinHeap a
merge HeapEmpty heap = heap
merge heap HeapEmpty = heap
merge lheap rheap = let
    HeapNode _ lval lc rc = lheap
    HeapNode _ rval _ _ = rheap
  in if rval < lval
    then merge rheap lheap
    else let rc' = merge rc rheap
      in if rank lc < rank rc'
        then HeapNode (rank lc + 1) lval rc' lc
        else HeapNode (rank rc' + 1) lval lc rc'

insert :: (Ord a) => a -> MinHeap a -> MinHeap a
insert = merge . singleton

pop :: (Ord a) => MinHeap a -> Maybe (a, MinHeap a)
pop HeapEmpty = Nothing
pop (HeapNode _ val lc rc) = Just (val, merge lc rc)

main :: IO()
main = do
  input <- lines <$> getContents
  let
    readInts = map (read :: String -> Int) . words
    [n, m] = readInts $ head input
    graph = buildGraph n . map readInts $ tail input
    resultString = concat . List.intersperse " " . map show $ dijkstra n graph
  putStrLn resultString

buildGraph :: Int -> [[Int]] -> Graph
buildGraph n edges = let
    initGraph = Sequence.replicate (n + 1) []
    addEdge :: [Int] -> Graph -> Graph
    addEdge [u, v, w] = Sequence.adjust ((w, v) :) u . Sequence.adjust ((w, u) :) v
  in foldr addEdge initGraph edges

dijkstra :: Int -> Graph -> [Int]
dijkstra n graph = let
    initHeap = singleton (0, 0, 1)
    initPaths = Sequence.replicate (n + 1) (-1)
    recurse :: DijkstraHeap -> Paths -> Paths
    recurse heap paths =
      case pop heap of
        Nothing -> paths
        Just ((dist, p, u), heap') ->
          if Sequence.index paths u == -1
          then let
              paths' = Sequence.update u p paths
              heap'' = foldr updateHeap heap' $ Sequence.index graph u
              updateHeap :: Edge -> DijkstraHeap -> DijkstraHeap
              updateHeap (w, v) = insert (dist + w, u, v)
            in recurse heap'' paths'
          else recurse heap' paths
    paths = recurse initHeap initPaths
    getPath :: Int -> [Int]
    getPath 0 = []
    getPath u = u : (getPath $ Sequence.index paths u)
    resultPath =
      case Sequence.index paths n of
        -1 -> [-1]
        _ -> getPath n
  in reverse resultPath