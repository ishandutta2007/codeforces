import Data.Functor
import Data.List

getStrings :: IO [String]
getStrings = tail . words <$> getContents

isBeautiful :: String -> Bool
isBeautiful (c:cs) = c == '1' && and [x == '0' | x <- cs]

solve :: [String] -> String
solve ss = if any (== "0") ss then "0" else r
  where
    start = case find (not . isBeautiful) ss of
        Just s -> s
        Nothing -> "1"
    end = replicate (sum [length s - 1 | s <- filter isBeautiful ss]) '0'
    r = start ++ end

main :: IO ()
main = getStrings >>= putStrLn . solve