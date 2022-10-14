main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = n `div` 2520