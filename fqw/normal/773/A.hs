import qualified Data.ByteString.Char8 as B
import           Data.Functor
import           Data.List
import           Data.Maybe
import qualified Data.Set              as S

getInts :: IO [Int]
getInts = map (fst . fromJust . B.readInt) <$> B.words <$> B.getContents
getIntegers :: IO [Integer]
getIntegers = map (fst . fromJust . B.readInteger) <$> B.words <$> B.getContents
pair []       = []
pair (x:y:rs) = (x, y) : pair rs
clamp u v w = max u $ min v $ w

main = do
    (_:xs) <- getIntegers
    putStrLn $ solveAll xs

solveAll []           = ""
solveAll (x:y:p:q:rs) = show (solve x y p q) ++ "\n" ++ solveAll rs

solve x y p q
    | p == 0 = if x == 0 then 0 else -1
    | p == q = if x == y then 0 else -1
    | otherwise = if m == 0 then ans else -1
  where
    (g, u0, v0) = gcdex q p
    (d, m) = divMod (y * p - x * q) g
    (u1, v1) = (u0 * d, -v0 * d)
    t = min (div u1 p) (div (v1-u1) (q-p))
    ans = v1 - q * t

gcdex a 0 = (a, 1, 0)
gcdex a b = let (g, u, v) = gcdex b (mod a b) in (g, v, u - (div a b) * v)