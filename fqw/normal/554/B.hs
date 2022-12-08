import Data.List

main = getContents >>= putStrLn . show . solve . tail . lines

solve :: [String] -> Int
solve = foldl1 max . map length . group . sort