main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = n * (n + 1) * (n + 2) * n * (n + 1) * (n + 2) * (n + 3) * (n + 4) `div` (1 * 2 * 3 * 1 * 2 * 3 * 4 * 5)