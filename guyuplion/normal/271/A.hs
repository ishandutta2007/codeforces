import Data.List
    
main = do
  x <- fmap (read) getContents
  print $ head $ filter (\x -> (length $ nub $ show x) == 4) [x + 1 .. ]