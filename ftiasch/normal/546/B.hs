import Data.List (sort)

main :: IO ()
main = print . solve . (map read . words . (!! 1) . lines) =<< getContents

solve :: [Int] -> Int
solve = fst . foldl step (0, 0) . sort
        where step (sum, m) a = let b = max (m + 1) a
                                    d = max 0 (b - a)
                                in (sum + d, b)