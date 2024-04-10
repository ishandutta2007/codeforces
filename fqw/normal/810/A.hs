import Data.Functor

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

parsePairs [] = []
parsePairs (x:y:rs) = (x, y) : parsePairs rs

main = do
    xs <- getInts
    print $ solve xs

solve (_:k:xs) = max 0 $ (2*k-1)*(length xs) - 2*(sum xs)