bool :: a -> a -> Bool -> a
bool f _ False = f
bool _ t True  = t

parse :: String -> [Int]
parse contents = map read (words a)
                 where [_, a] = lines contents

solve :: [Int] -> Bool
solve a = any isPermutation . take n . iterate rotate $ a
          where n             = length a
                isPermutation = (== [0..n - 1])
                rotate        = zipWith plus (cycle [1, n - 1])
                x `plus` y    = (x + y) `rem` n

main :: IO ()
main = putStrLn . bool "No" "Yes" . solve . parse =<< getContents