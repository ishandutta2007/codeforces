readInt x = read x :: Int
main = interact $ show . solve . (map readInt) . words

go os [] = -1
go os (x:xs) = if elem x os then 1 else p $ go (x:os) xs
	where p i = if i < 0 then i else i+1

solve (p:n:xs) = go [] $ map (`mod` p) xs