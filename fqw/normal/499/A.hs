import Data.Functor

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

main = getInts >>= putStrLn . show . solve

solve :: [Int] -> Int
solve (n:x:rs) = solve' x 0 rs

solve' x t [] = 0
solve' x t (l:r:rs) = (r-l+1) + mod (l-t-1) x + solve' x r rs