import qualified Data.Map as Map

main = getContents >>= putStrLn . solve . tail . words

solve :: [String] -> String
solve (s:t:[]) = let (v, i, j) = foldl1 min options in unlines [show (v + v0), show i ++ " " ++ show j]
    where table = getTable s t
          options = (0, -1, -1) : concat [zipWith getOption table $ drop i table | i <- [1..length table]]
          v0 = diff s t

diff :: String -> String -> Int
diff s t = length . filter (uncurry (/=)) $ zip s t

getTable :: String -> String -> [(Char, Char, Int)]
getTable s t = map (\((c1, c2), i) -> (c1, c2, i)) . Map.toList $ foldl f Map.empty (zip3 s t [1..])
    where f m (c1, c2, i) = Map.insert (c1, c2) i m

getOption :: (Char, Char, Int) -> (Char, Char, Int) -> (Int, Int, Int)
getOption (a1, a2, ai) (b1, b2, bi) = (v12 + v21 - v11 - v22, ai, bi)
    where v11 = if a1 == b1 then 1 else 2
          v12 = if a1 == b2 then 1 else 2
          v21 = if a2 == b1 then 1 else 2
          v22 = if a2 == b2 then 1 else 2