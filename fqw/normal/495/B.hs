import Data.List

main = getLine >>= putStrLn . solve . map read . words

solve :: [Int] -> String
solve (a:b:[])
    | a < b = "0"
    | a == b = "infinity"
    | a > b = show $ solve' a b

solve' a b = length . filter (\x -> mod a x == b) $ factors (a - b)

factors n = nub (xs ++ ys)
    where xs = filter (\x -> mod n x == 0) $ takeWhile (\x -> x * x <= n) [1 ..]
          ys = map (\x -> div n x) xs