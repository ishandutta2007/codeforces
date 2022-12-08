readInt x = read x :: Int
main = interact $ show . solve' . map readInt . words

solve' (_:xs) = if length xs < 3 then length xs else solve xs
solve xs =
	maximum $ zipWith f ([(0,0)] ++ init ls) (tail rs ++ [(0,0)])
	where
		ls = incLengths xs
		rs = map (\x -> (-fst x,snd x)) (reverse $ incLengths $ map negate $ reverse xs)
		f a b = if (fst a + 2 <= fst b) then (1 + snd a + snd b) else (1 + max (snd a) (snd b))

incLengths (x:xs) = scanl f (x,1) xs
	where f a x = if fst a < x then (x,snd a+1) else (x,1)