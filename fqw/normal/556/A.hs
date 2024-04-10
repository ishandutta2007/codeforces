main = getContents >>= putStrLn . show . solve . last . words

solve :: String -> Int
solve cs = n - 2 * min p q
    where n = length cs
          p = length $ filter (== '0') cs
          q = length $ filter (== '1') cs