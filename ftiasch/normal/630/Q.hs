import Control.Monad (liftM)

solve :: Double -> Double -> Double
solve n l =
    let a = pi / n in
    let l' = l / 2 / sin a in
    let h = sqrt (l ** 2 - l' ** 2) in
    l' * l' * sin (2 * a) / 2 * h / 3 * n

main :: IO ()
main = do
    [l_3, l_4, l_5] <- (map read . words) `liftM` getContents :: IO [Double]
    print $ solve 3 l_3 + solve 4 l_4 + solve 5 l_5