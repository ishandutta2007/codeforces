import Data.List

main = getContents >>= putStrLn . (\b -> if b then "Yes" else "No") . solve . map read . tail . words

solve :: [Int] -> Bool
solve xs = foldl1 (||) [solve' xs i | i <- [1..length xs]]

solve' xs i = let ys = go xs i (length xs) in ys == [0..length xs-1]

go [] _ _ = []
go (x:xs) i n = mod (x + i) n : go xs (n - i) n