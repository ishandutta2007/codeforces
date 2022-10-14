import Data.List (sort)
import Data.Int (Int64)

type Input  = (Int64, [(Int64, Int64)])

parse :: String -> Input
parse contents =
    let (l : ls) = lines contents
        (_, d)   = p l
    in  (d, map p ls)
    where p l = (a, b) where [a, b] = map read . words $ l

solve :: Input -> Int64
solve (d, a') = maximum . map fst $ scanl step (0, a) a
                where a = sort a'
                      step (s, b) (m, f) =
                          let (xs, b') = break (\(m', _) -> m' > m - d) b
                          in  (s + f - sum (map snd xs), b')

main :: IO ()
main = print . solve . parse =<< getContents