import           Data.Bits
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
    (n:x:y:_) <- getIntegers
    print $ fst $ solve n x y

solve 0 x y = (0, x)
solve n x y = (ans0, ans1)
  where
    (m, r) = divMod n 2
    (tmp0, tmp1) = solve m x y
    ans0 = min (n*x) $ if r == 0 then y + tmp0 else y + x + min tmp0 tmp1
    ans1 = min ((n+1)*x) $ if r == 1 then y + tmp1 else y + x + min tmp0 tmp1