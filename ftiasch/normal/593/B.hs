import Data.Char (ord)
import Data.List (sort)

type Input  = (Integer, Integer, [(Integer, Integer)])
type Output = Bool

readInteger :: String -> Integer
readInteger ('-' : s) = - (readInteger s)
readInteger s = foldl (\t c -> t * 10 + toInteger (ord c) - 48) 0 s

parse :: String -> Input
parse contents = (x_1, x_2, map pair ls)
    where (_ : l1 : ls) = lines contents
          (x_1, x_2)    = pair l1
          pair l        = let [a, b] = map readInteger . words $ l in (a, b)

check :: [(Integer, Integer)] -> Bool
check []  = False
check [_] = False
check ((x, y) : (x', y') : xss) = (x < x' && y > y') || check ((x', y') : xss)

solve :: Input -> Output
solve (x_1, x_2, ls) = check . sort . map y $ ls
    where y (k, b) = (k * x_1 + b, k * x_2 + b)

format :: Output -> String
format True  = "Yes"
format False = "No"

main :: IO ()
main = putStrLn . format . solve . parse =<< getContents