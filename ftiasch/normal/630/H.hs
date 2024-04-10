main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = s * s * 120
    where s = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) `div` 120