import Data.List

main = do
    string <- getContents
    let answers = solve string
    sequence (map (putStrLn.show) answers)

solve string = let n = read sn :: Int; k = read sk :: Int in computeAnswer k [read s :: Int | s <- rest]
	       where (sn:sk:rest) = words string

computeAnswer k a = let b = sort a in getK k$head b:zipWith (-) (tail b) b
getK 0 _ = []
getK k [] = replicate k 0
getK k (x:xs) | x == 0 = getK k xs
	      | otherwise =  x : getK (k - 1) xs