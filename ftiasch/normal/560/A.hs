parse :: String -> [Int]
parse contents = map read . words $ a
                 where [_, a] = lines contents

bool :: a -> a -> Bool -> a
bool f _ False = f
bool _ t True  = t

solve :: [Int] -> Int
solve = bool 1 (-1) . (== 1) . minimum

main :: IO ()
main = print . solve . parse =<< getContents