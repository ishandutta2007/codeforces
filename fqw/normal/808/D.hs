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
    _:xs <- getIntegers
    putStrLn $ if solve xs then "YES" else "NO"

solve xs = mod s 2 == 0 && (res1 || res2) where
    s = sum xs
    want = - div s 2
    res1 = go xs want S.empty
    res2 = go (reverse xs) want S.empty
    go [] want s     = S.member want s
    go (x:xs) want s = S.member want s || go xs (want+x) (S.insert x s)