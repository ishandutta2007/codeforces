import Control.Exception.Base
import Data.Functor

readInts :: IO [Int]
readInts = map read <$> words <$> getContents

main = readInts >>= putStrLn . show . solve

solve :: [Int] -> Int
solve xs = assert (length xs `mod` 4 == 1) $ solve' $ tail xs

solve' :: [Int] -> Int
solve' [] = 0
solve' (x1:y1:x2:y2:ps) = (x2-x1+1) * (y2-y1+1) + solve' ps