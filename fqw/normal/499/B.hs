import qualified Data.Map as Map
import Data.Functor

parseLine :: IO (Map.Map String String) -> Int -> IO (Map.Map String String)
parseLine ms index = do
    m <- ms
    [x, y] <- words <$> getLine
    return $ Map.insert x (if length x <= length y then x else y) m

unwrap (Just x) = x

main = do
    [n, m] <- map read <$> words <$> getLine :: IO [Int]
    p <- foldl parseLine (return Map.empty) [1..m]
    as <- words <$> getLine
    bs <- return $ map (\x -> unwrap (Map.lookup x p)) as
    putStrLn . unwords $ bs