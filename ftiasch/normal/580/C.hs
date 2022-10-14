import Data.Array
import Data.Char (ord)
import Data.List (groupBy, sortBy)
import Data.Ord (comparing)
import Data.Tuple (swap)

type IntArray a = Array Int a

type Input = (Int, IntArray Int, IntArray [Int])

readInt :: String -> Int
readInt = foldl step 0 where step s a = s * 10 + ord a - 48

readPair :: String -> (Int, Int)
readPair s = (a, b)
    where [a, b] = map readInt . words $ s

parseV :: Int -> String -> IntArray Int
parseV n l = listArray (1, n) a
    where a = map readInt . words $ l

sortOn :: Ord b => (a -> b) -> [a] -> [a]
sortOn f = map snd . sortBy (comparing fst) . map (\x -> let y = f x in y `seq` (y, x))

groupOn :: Ord b => (a -> b) -> [a] -> [[a]]
groupOn k = groupBy f . sortOn k
    where f x y = k x == k y

parseE :: Int -> [String] -> IntArray [Int]
parseE n ls =
    let es = map readPair ls
        gs = groupOn fst (es ++ map swap es)
    in  listArray (1, n) (map (map snd) gs)

parse :: String -> Input
parse contents =
    let (l0 : l1 : ls) = lines contents
        [n, m] = map readInt . words $ l0
    in  (m, parseV n l1, parseE n ls)

solve :: Input -> Int
solve (m, a, tree) = dfs (-1) 0 1
    where dfs :: Int -> Int -> Int -> Int
          dfs p k v =
              let a' = a ! v
                  k' = if a' == 0 then 0 else k + 1
                  nv = filter (/= p) $ tree ! v in
              if   k' > m
              then 0
              else if   null nv
                   then 1
                   else sum . map (dfs v k') $ nv

main :: IO ()
main = print . solve . parse =<< getContents