main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = 2 ^ (n + 1) - 2