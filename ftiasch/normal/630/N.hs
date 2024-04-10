main :: IO ()
main = solve . parse =<< getContents

parse :: String -> (Double, Double, Double)
parse line = (a, b, c) where [a, b, c] = map read . words $ line

solve :: (Double, Double, Double) -> IO ()
solve (a, b, c)
    | a < 0 = solve (-a, -b, -c)
    | otherwise = do { let delta = sqrt $ b * b - 4 * a * c
                     ; print $ (-b + delta) / (2 * a)
                     ; print $ (-b - delta) / (2 * a)
                     }