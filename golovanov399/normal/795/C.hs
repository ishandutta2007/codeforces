import Data.Char
import Data.List

solve :: String -> IO ()

f :: Int -> String
f n
   | mod n 2 == 1	= '7' : (f (n - 3))
   | n == 0 = ""
   | otherwise = '1' : (f (n - 2))

solve = putStrLn . f . (read :: String -> Int)

main = getContents >>= solve