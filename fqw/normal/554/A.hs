import Data.List

main = getLine >>= putStrLn . show . solve

solve :: String -> Int
solve s = length . nub $ [take i s ++ [c] ++ drop i s | i <- [0..length s], c <- ['a'..'z']]