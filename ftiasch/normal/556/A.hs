{-# LANGUAGE BangPatterns #-}

import Data.List (foldl')

parse :: String -> String
parse contents = s where [_, s] = lines contents

solve :: String -> Int
solve = length . foldl' step []
        where step []       !a = [a]
              step (s : ss) !a
                | s /= a    = ss
                | otherwise = a : s : ss

main :: IO ()
main = print . solve . parse =<< getContents