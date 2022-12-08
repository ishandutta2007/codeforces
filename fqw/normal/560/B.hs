import Data.Functor

getInts :: IO [Int]
getInts = map read <$> words <$> getContents

main = getInts >>= putStrLn . (\b -> if b then "YES" else "NO") . solve

solve (a1:b1:a2:b2:a3:b3:[]) = or [
    check a1 b1 (a2 + a3) (max b2 b3),
    check a1 b1 (a2 + b3) (max b2 a3),
    check a1 b1 (b2 + a3) (max a2 b3),
    check a1 b1 (b2 + b3) (max a2 a3)]

check a1 b1 a2 b2 = or [a2 <= a1 && b2 <= b1, a2 <= b1 && b2 <= a1]