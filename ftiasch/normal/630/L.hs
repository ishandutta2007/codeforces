main :: IO ()
main = putStr . reverse . take 5 . reverse . show . (^5) . read . shuffle =<< getLine

shuffle :: String -> String
shuffle [x1, x2, x3, x4, x5] = [x1, x3, x5, x4, x2]