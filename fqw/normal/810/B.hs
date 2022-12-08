import qualified Data.ByteString.Char8 as B
import           Data.Functor
import           Data.List
import           Data.Maybe

getInts :: IO [Int]
getInts = map (fst . fromJust . B.readInt) <$> B.words <$> B.getContents
parsePairs []       = []
parsePairs (x:y:rs) = (x, y) : parsePairs rs
clamp u v w = max u $ min v $ w

main = do
    _:f:xs <- getInts
    print $ solve f (parsePairs xs)

solve :: Int -> [(Int, Int)] -> Integer
solve f ps = base + bonus where
    base = sum . map toInteger $ [min u v | (u, v) <- ps]
    bonus = sum . map toInteger . take f . reverse . sort $ [clamp 0 u (v - u) | (u, v) <- ps]