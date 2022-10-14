type Input = (Int, [(Int, Int)])

parse :: String -> Input
parse contents = (n, [(min1, max1), (min2, max2), (min3, max3)])
                 where [n, min1, max1, min2, max2, min3, max3] = map read . words $ contents

solve :: Input -> [Int]
solve (_, [])           = []
solve (n, (_, ma) : cs) = a : solve (n - a, cs)
                          where a = min ma (n - sum (map fst cs))

pprint :: [Int] -> IO ()
pprint = putStrLn . unwords . map show

main :: IO ()
main = pprint . solve . parse =<< getContents