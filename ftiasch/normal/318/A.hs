main :: IO()
main = interact mainFunction

mainFunction :: String -> String
mainFunction input = let [n, k] = map parseInteger . words $ input
                     in show $ solve n k 

parseInteger :: String -> Integer
parseInteger = read

solve :: Integer -> Integer -> Integer
solve n k = let oddCount = (n + 1) `div` 2
            in if k <= oddCount
               then 2 * k - 1
               else 2 * (k - oddCount)