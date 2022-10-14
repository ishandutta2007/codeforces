import Data.List (group, sort)

main :: IO ()
main = print . solve . parse . lines =<< getContents

type Input = String

parse :: [String] -> Input
parse [_, s] = s
parse _ = undefined

delta :: Char -> (Int, Int)
delta 'U' = (0, 1)
delta 'R' = (1, 0)
delta 'D' = (0, -1)
delta 'L' = (-1, 0)
delta _ = undefined

solve :: Input -> Int
solve = sum . map count . group . sort . scanl step (0, 0)
    where step (x, y) c = let (x', y') = delta c in (x + x', y + y')
          count a = let n = length a in n * (n - 1) `div` 2