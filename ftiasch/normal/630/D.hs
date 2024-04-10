main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = 1 + (1 + n) * n * 3