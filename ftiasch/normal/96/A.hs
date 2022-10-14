import Data.List
main = interact work

work :: String -> String
work input = if (maximum . map length . group) input >= 7 then "YES" else "NO"