import Data.Functor

getInts :: IO [Integer]
getInts = map read <$> words <$> getContents

main = getInts >>= putStrLn . show . solve

solve (a:b:[]) = if b == 0 then 0 else div a b + solve (b:c:[]) where c = mod a b