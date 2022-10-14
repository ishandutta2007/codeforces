main :: IO ()
main = print . solve . map read . words =<< getContents

solve :: [Integer] -> Integer
solve [k, n, w] = max 0 (k * (w + 1) * w `div` 2 - n)