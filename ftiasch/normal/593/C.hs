type Input  = [[Integer]]
type Output = [Exp]

parse :: String -> Input
parse = toList . unzip . map pair . tail . lines
    where pair l        = let [x, y, _] = map read . words $ l in (x, y)
          toList (a, b) = [a, b]

data Exp = Abs      Exp
         | Add      Exp Exp
         | Subtract Exp Exp
         | Multiply Exp Exp
         | Constant Integer
         | Variable

instance Show Exp where
    show g = go g ""
        where go :: Exp -> String -> String
              go (Abs      e)   = ("abs(" ++) . go e . (")" ++)
              go (Add      e f) = ("(" ++) . go e . ("+" ++) . go f . (")" ++)
              go (Subtract e f) = ("(" ++) . go e . ("-" ++) . go f . (")" ++)
              go (Multiply e f) = ("(" ++) . go e . ("*" ++) . go f . (")" ++)
              go (Constant c)   = (show c ++)
              go (Variable)     = ("t" ++)

instance Num Exp where
    abs         = Abs
    (+)         = Add
    (-)         = Subtract
    (*)         = Multiply
    fromInteger = Constant
    signum      = undefined

at :: Integer -> Exp
at x = 2 - abs (d (x - 1) - d (x + 1))
    where d :: Integer -> Exp
          d a
            | a >= 0    = abs (Variable - fromInteger   a)
            | otherwise = abs (Variable + fromInteger (-a))

solve :: Input -> Output
solve = map solve1
    where solve1 :: [Integer] -> Exp
          solve1 = sum . zipWith (*) (map at [0..]) . map (fromInteger . (`div` 2))

format :: Output -> String
format = unlines . map show

main :: IO ()
main = putStrLn . format . solve . parse =<< getContents