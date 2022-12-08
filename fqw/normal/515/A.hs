import Data.Functor

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

main = getInts >>= putStrLn . (\b -> if b then "Yes" else "No") . solve

solve :: [Int] -> Bool
solve (a:b:s:[])
    | abs a + abs b > s = False
    | mod (abs a + abs b - s) 2 == 0 = True
    | otherwise = False