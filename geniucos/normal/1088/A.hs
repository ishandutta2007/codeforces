main = do
   strX <- getLine
   let x = read strX
   putStrLn$f x

l x = [(a, b) | a <- [1..x], b <- [1..x], mod a b == 0 && a * b > x && a < b * x]
f x | null lst = "-1"
    | otherwise = let (a, b) = head lst in show a ++ " " ++ show b
  where lst = l x