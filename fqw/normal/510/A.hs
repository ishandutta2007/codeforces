import Data.Functor

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

main = getInts >>= mapM putStrLn . solve

solve :: [Int] -> [String]
solve (n:m:[]) = solve' n m 1

solve' n m i
    | i > n = []
    | mod i 2 == 1 = replicate m '#' : la
    | mod i 4 == 2 = (replicate (m-1) '.' ++ "#") : la
    | mod i 4 == 0 = ("#" ++ replicate (m-1) '.') : la
    where la = solve' n m (i+1)