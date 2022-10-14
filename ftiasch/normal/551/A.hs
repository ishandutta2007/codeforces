type Input  = [Int]
type Output = [Int]

parse :: String -> Input
parse contents = rs where [_, rs] = map (map read . words) . lines $ contents

solve :: Input -> Output
solve rs = map rank rs
           where rank r = 1 + length (filter (> r) rs)

pretty :: Output -> String
pretty = unwords . map show

main :: IO ()
main = putStrLn . pretty . solve . parse =<< getContents