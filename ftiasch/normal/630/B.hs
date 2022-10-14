import Control.Monad (liftM)

main :: IO ()
main = do
    [n, t] <- (map read . words) `liftM` getContents :: IO [Double]
    print $ n * (1.000000011 ** t)