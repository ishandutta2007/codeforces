type Input  = [String]
type Output = Int

parse :: String -> Input
parse = tail . lines

chars :: String
chars = ['a'..'z']

solve :: Input -> Output
solve ws = maximum [sum . map length . filter (all (\c -> c == a || c == b)) $ ws | a <- chars, b <- chars]

format :: Output -> String
format = show

main :: IO ()
main = putStrLn . format . solve . parse =<< getContents