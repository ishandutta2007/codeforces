import Data.Char
import Data.List

solve :: String -> IO()

add_one x = if x == -1 then -1 else x + 1

has_one :: String -> Int
has_one s = num_after s
    where
        num_after s
            | null s = -1
            | head s == '1' = tmp $ tail s
            | head s == '0' = num_after $ tail s
            | otherwise = -1
        tmp s
            | null s = 0
            | head s == '1' = tmp $ tail s
            | head s == '0' = (tmp $ tail s) + 1
            | otherwise = 0

solve s = putStrLn $ if (has_one s >= 6) then "yes" else "no"

main :: IO()
main = getContents >>= solve