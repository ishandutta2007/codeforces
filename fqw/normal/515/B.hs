import Data.Functor
import Data.List

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

main = getInts >>= putStrLn . (\b -> if b then "Yes" else "No") . solve

solve :: [Int] -> Bool
solve (n:m:as) = (==g) . length . nub $ map f xs ++ map f ys where
    xn:as2 = as
    yn:as3 = drop xn as2
    xs = take xn as2
    ys = take yn as3
    g = gcd n m
    f = (flip mod) g