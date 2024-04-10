main :: IO ()
main = getLine >>= putStrLn . showFraction . solve . read
  where
    showFraction (a, b) = let g = gcd a b
                          in show (div a g) ++ "/" ++ show (div b g)
    gcd a b = if b == 0 then a else gcd b (mod a b)

cal :: Integer -> Integer -> (Integer, Integer)
cal n r
    | r >= n    = (0, r - n)
    | otherwise = (c + 1, r2) where (c, r2) = cal n (r * 2)

solve :: Integer -> (Integer, Integer)
solve n | mod n 2 == 0 = (a + b, b) where (a, b) = solve (div n 2)
solve 1                = (0, 1)
solve n                = (a, b - 1) where (a, b) = go n 1

go :: Integer -> Integer -> (Integer, Integer)
go n r = let (c, r2) = cal n r
             (a, b)  = if r2 == 1 then (0, 1) else go n r2
         in (a + 2^c * r * c * b, 2^c * b)