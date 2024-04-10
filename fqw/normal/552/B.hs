import Control.Exception.Base
import Data.Functor

readInts :: IO [Integer]
readInts = map read <$> words <$> getContents

main = readInts >>= putStrLn . show . solve . head

solve :: Integer -> Integer
solve = go 1 1 10 where 
    go len l r x = if x < r then (x-l+1)*len else (r-l)*len + go (len+1) (l*10) (r*10) x