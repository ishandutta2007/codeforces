import Control.Applicative

main = getLine >>= putStrLn . solve

solve :: String -> String
solve s = head . (++ ["NA"]) . filter ((==) <*> reverse) $ rs
    where rs = [take i s ++ [c] ++ drop i s | i <- [0..length s], c <- ['a'..'z']]