import Control.Exception.Base
import Data.Functor

readInts :: IO [Int]
readInts = map read <$> words <$> getContents

bool x _ True = x
bool _ y False = y

main = readInts >>= putStrLn . bool "YES" "NO" . solve

solve :: [Int] -> Bool
solve (w:m:[]) = go w m
go w m 
    | m == 0 = True
    | mod m w <= 1 = go w $ div m w
    | mod (m+1) w == 0 = go w $ div (m+1) w
    | otherwise = False