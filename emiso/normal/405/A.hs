import Control.Applicative

splitHalf :: [a] -> ([a], [a])
splitHalf [] = ([], [])
splitHalf [x] = ([x], [])
splitHalf (x:y:z) = (x : odd, y : even)
  where
    (odd, even) = splitHalf z


merge :: (Num a, Ord a) => [a] -> [a] -> [a]
merge x y
  | null x = y
  | null y = x
  | otherwise = 
    if head x < head y
      then head x : merge (tail x) y
      else head y : merge x  (tail y)

mergeSort :: (Num a, Ord a) => [a] -> [a]
mergeSort [x] = [x]
mergeSort l = merge (mergeSort left) (mergeSort right)
  where (left, right) = splitHalf l

parseLine = map read . words <$> getLine

toString :: [Int] -> String
toString [] = "\n"
toString x  = show(head x) ++ " " ++ toString(tail x)  

main :: IO()
main = do
  _   <- parseLine
  arr <- parseLine
  let l = mergeSort arr
  putStrLn (toString l)