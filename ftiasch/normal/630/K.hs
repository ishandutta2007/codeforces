main :: IO ()
main = print . solve . read =<< getContents

solve :: Integer -> Integer
solve n = sum $ map go [ ( 1, 1)
                       , (-1, 2)
                       , (-1, 3)
                       , (-1, 5)
                       , (-1, 7)
                       , ( 1, 6)
                       , ( 1, 10)
                       , ( 1, 14)
                       , ( 1, 15)
                       , ( 1, 21)
                       , ( 1, 35)
                       , (-1, 2*3*5)
                       , (-1, 2*3*7)
                       , (-1, 2*5*7)
                       , (-1, 3*5*7)
                       , ( 1, 2*3*5*7)
                       ]
    where go (s, d) = s * (n `div` d)