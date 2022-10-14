import Control.Monad
import Data.Char

main = getLine >>= putStrLn . capitalize

capitalize :: String -> String
capitalize (x:xs) = (toUpper x):xs