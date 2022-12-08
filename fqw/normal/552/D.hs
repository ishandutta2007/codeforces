import Control.Exception.Base
import Debug.Trace
import Data.Functor
import Data.List

readInts :: IO [Int]
readInts = map read <$> words <$> getContents
parsePairs :: [Int] -> [(Int, Int)]
parsePairs [] = []
parsePairs (x:y:rs) = (x, y) : parsePairs rs

main = readInts >>= putStrLn . show . solve . parsePairs . tail

solve :: [(Int, Int)] -> Integer
solve rs = let n = toInteger $ length rs in n * (n-1) * (n-2) `div` 6 - countDegen rs

countDegen :: [(Int, Int)] -> Integer
countDegen = f . sort where
    f [] = 0
    f (r:[]) = 0
    f ((x0, y0):rs) = go (map (\(x, y) -> (x-x0, y-y0)) rs) + f rs

simplify (x, y) 
    | x == 0 = (0, 1)
    | y == 0 = (1, 0)
    | otherwise = let g = gcd x y in f (div x g) (div y g)
    where f x y = if x > 0 then (x, y) else (-x, -y)

go = sum . map (pairs . length) . group . sort . map simplify
    where pairs x = toInteger $ x * (x - 1) `div` 2