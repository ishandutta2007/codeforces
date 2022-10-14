main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n
    | n == 3 = 24
    | otherwise = 4 * (2 * 3 * 4 ^ (n - 3) + (n - 3) * 3 * 3 * 4 ^ (n - 4))