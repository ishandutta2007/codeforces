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
    (a1:b1:a2:b2:l:r:[]) <- getIntegers
    print $ solve a1 b1 a2 b2 l r

solve a1 b1 a2 b2 l r = case merge a1 b1 a2 b2 of
    Nothing     -> 0
    Just (a, b) -> count a b r - count a b (l-1)

count :: Integer -> Integer -> Integer -> Integer
count a b r = max 0 $ 1 + div (r-b) a

gcdex a 0 = (a, 1, 0)
gcdex a b = let (g, u, v) = gcdex b (mod a b) in (g, v, u - (div a b) * v)

adjust (x, y) (dx, dy) = (x - dx * t, y - dy * t)
  where
    t = min (div x dx) (div y dy)

merge a1 b1 a2 b2 = if m == 0 then Just ans else Nothing
  where
    (g, u, v) = gcdex a1 a2
    (t, m) = divMod (b2-b1) g
    (x0, y0) = (u * t, -v * t)
    (dx, dy) = (div a2 g, div a1 g)
    (x, y) = adjust (x0, y0) (dx, dy)
    ans = (a1 * a2 `div` g, x * a1 + b1)