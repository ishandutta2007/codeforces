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
    (_:m:xs) <- getInts
    print $ solve m (pair $ map toInteger xs)

solve :: Int -> [(Integer, Integer)] -> Integer
solve m ps = go a3 0 m r0 r1
  where
    a1 = reverse . sort $ map snd $ filter ((==1) . fst) ps
    a2 = reverse . sort $ map snd $ filter ((==2) . fst) ps
    a3 = reverse . sort $ map snd $ filter ((==3) . fst) ps
    (r0, r1) = prepare a1 a2

removeOutdated [] m     = [(0, 0)]
removeOutdated (r:rs) m = if fst r <= m then (r:rs) else removeOutdated rs m

go :: [Integer] -> Integer -> Int -> [(Int, Integer)] -> [(Int, Integer)] -> Integer
go a3 s3 m r0 r1 = max current next
  where
    r0' = removeOutdated r0 m
    r1' = removeOutdated r1 m
    current = s3 + (snd . head $ if mod m 2 == 0 then r0' else r1')
    next = if m >= 3 && not (null a3)
            then go (tail a3) (s3 + head a3) (m-3) r0' r1'
            else 0

prepare :: [Integer] -> [Integer] -> ([(Int, Integer)], [(Int, Integer)])
prepare a1 a2 = (reverse $ zip [2,4..] v0', reverse $ zip [1,3..] v1')
  where
    (a10, a11) = evenOddSplit $ a1 ++ [0, 0]
    v0 = a2 ++ zipWith (+) a10 a11
    v1 = a2 ++ zipWith (+) (tail a10) a11
    v0' = scanl1 (+) $ reverse $ sort v0
    v1' = map (+ head a10) $ scanl (+) 0 $ reverse $ sort v1

evenOddSplit []     = ([], [])
evenOddSplit (x:xs) = let (e, o) = evenOddSplit xs in (x:o, e)