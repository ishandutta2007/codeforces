import qualified Data.Set as Set
import qualified Data.Map as Map    
import Control.Applicative

main = getContents >>= putStrLn . solve . tail . words


solve :: [String] -> String
solve rs = unlines $ [show $ Set.size s] ++ [upwrap (Map.lookup x m) ++ " " ++ x | x <- Set.toList s]
    where (s, m) = solve' $ reverse rs
          upwrap (Just x) = x

solve' :: [String] -> (Set.Set String, Map.Map String String)
solve' [] = (Set.empty, Map.empty)
solve' (y:x:rs) = (s', m')
    where (s, m) = solve' rs
          s' = Set.delete x . Set.insert y $ s
          m' = case Map.lookup x m of
            Nothing -> Map.insert y x m
            Just z -> Map.insert y z m
solve' _ = (Set.fromList ["a","b"], Map.fromList [("a","A"), ("b","B")])