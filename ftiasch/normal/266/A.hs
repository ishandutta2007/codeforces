main :: IO()
main = 
    getLine >>
    getLine >>= \s -> 
    print $ length . filter id $ zipWith (==) s (tail s)