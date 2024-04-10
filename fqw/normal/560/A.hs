import Data.Functor

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

main = getInts >>= putStrLn . show . solve

solve (_:xs) = if elem 1 xs then -1 else 1