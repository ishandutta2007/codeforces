main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = (n - 1) `mod` 2 + 1