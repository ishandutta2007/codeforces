main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = binom n 7 + binom n 6 + binom n 5
    where binom n k = (product [n - k + 1 .. n]) `div` (product [1..k])