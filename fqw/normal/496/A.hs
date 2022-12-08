import Data.Functor

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

main = getInts >>= putStrLn . show . solve . tail

solve xs = foldl1 min [cal (take (i-1) xs ++ drop i xs) | i <- [2 .. length xs - 1]]

cal xs = foldl1 max $ zipWith (-) (tail xs) xs