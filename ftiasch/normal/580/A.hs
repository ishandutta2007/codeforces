type Input = [Int]

parse :: String -> Input
parse = map read . words . (!! 1) . lines

solve :: Input -> Int
solve = snd . go
        where go []       = undefined
              go [_]      = (1, 1)
              go (x : xs) = let (l, m) = go   xs
                                y      = head xs in
                            if x <= y
                            then let l' = l + 1 in (l', max m l')
                            else (1, m)

main :: IO ()
main = print . solve . parse =<< getContents