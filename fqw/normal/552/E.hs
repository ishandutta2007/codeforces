
import Data.Char

type Pair = (Integer, Integer)
type State = (Integer, Integer, Integer, Integer)

splitEvenOdd :: [a] -> ([a], [a])
splitEvenOdd = foldr f ([], []) where f v (xs, ys) = (ys, v:xs)

main = getLine >>= putStrLn . show . solve . splitEvenOdd

solve :: (String, String) -> Integer
solve (os, vs) = ans where
    xs = map (toInteger . digitToInt) vs
    (ans, _, _) = go (1, 0) os xs

go :: Pair -> [Char] -> [Integer] -> (Integer, [State], Pair)
go (u, v) [] (x:xs) = (u * x + v, [(x, 0, 1, 0)], (1, 0))
go l (o:os) (x:xs) = (ans', states', pair') where
    (ans, states, pair) = go (updatePair l o x) os xs
    pair' = updatePair pair o (head xs)
    states' = updateStates states o x pair'
    ans' = max ans $ updateAns l states'

updatePair (u, v) o x = if o == '+' then (1, u * x + v) else (u * x, v)

updateStates :: [State] -> Char -> Integer -> Pair -> [State]
updateStates states o x (ru, rv) = tmp' where
    tmp = [if o == '+' then (x, u + v, w, z) else (x * u, v, w, z) | (u, v, w, z) <- states]
    tmp' = if ru > 1 then (x, 0, ru, rv):tmp else tmp

updateAns (lu, lv) states = foldr1 max [(u + v) * w * lu + lv + z | (u, v, w, z) <- states]