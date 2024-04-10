import Data.Char

main = getContents >>= putStrLn . solve . last . words

solve :: String -> String
solve s = foldl1 min [add k (drop i s ++ take i s) | i <- [1 .. length s], k <- [0 .. 9]]

add v s = map (intToDigit . (`mod` 10) . (+ v) . digitToInt) s