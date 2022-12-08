main = getLine >>= putStrLn . show . solve . read

solve x = solve' (x + 1) - x

solve' :: Int -> Int
solve' x = if lucky x then x else solve' (x + 1)

lucky :: Int -> Bool
lucky x
    | x < 0 = lucky (-x)
    | x == 0 = False
    | mod x 10 == 8 = True
    | otherwise = lucky (div x 10)