type Input = String
type Output = Int

main :: IO ()
main = print . solve . parse =<< getContents

parse :: String -> Input
parse = id

solve :: Input -> Output
solve contents
    | period == "week" = solveWeek x
    | period == "month" = solveMonth x
    | otherwise = undefined
    where [x', _, period] = words contents
          x = read x'

solveWeek :: Int -> Int
solveWeek x
    | x `elem` [5, 6] = 53
    | otherwise = 52

solveMonth :: Int -> Int
solveMonth x
    | x == 31 = 7
    | x >= 30 = 11
    | otherwise = 12