import Control.Arrow ((&&&))
import Data.List (group, sort)

type Input = [[Int]]

parse :: String -> Input
parse = map parseLine . tail . lines
        where parseLine = map read . words

select :: [(Int, Int)] -> Int
select = negate . snd . maximum

solve :: Input -> Int
solve = stage2 . stage1
        where stage1 = map (select. flip zip [-1, -2..]) :: [[Int]] -> [Int]
              stage2 = select . map (length &&& negate . head) . group . sort

main :: IO ()
main = print . solve . parse =<< getContents