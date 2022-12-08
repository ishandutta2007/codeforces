main = getLine >>= putStrLn . show . product . map cal

cal c = case c of
    '0' -> 2
    '1' -> 7
    '2' -> 2
    '3' -> 3
    '4' -> 3
    '5' -> 4
    '6' -> 2
    '7' -> 5
    '8' -> 1
    '9' -> 2