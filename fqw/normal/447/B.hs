readInt x = read x :: Int
main = interact $ show . solve' . words
solve' (s:k:ws) = solve s (readInt k) (map readInt ws)

solve s k ws = sum $ zipWith (*) [1..] $ (map (\c -> ws !! (ord c)) s) ++ replicate k (maximum ws)
	where ord c = fromEnum c - 97