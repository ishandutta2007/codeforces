import Data.Functor
import Data.List

getIntegers :: IO [Integer]
getIntegers = map read <$> words <$> getLine

parsePairs [] = []
parsePairs (x:y:rs) = (x, y) : parsePairs rs

solve :: Integer -> Integer -> Integer -> [Integer]
solve l r k = takeWhile (<=r) $ dropWhile (<l) $ iterate (*k) 1

main = do
    [l, r, k] <- getIntegers
    putStrLn $ let xs = solve l r k in
        if null xs then "-1" else intercalate " " (map show $ xs)