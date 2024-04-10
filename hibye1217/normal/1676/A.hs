import Data.Char(digitToInt)

f :: String -> Int

f "" = 0
f s = do
    (f (take ((length s)-1) (drop 1 s))) + (digitToInt (head s))

solve 0 = return ()
solve t = do
    s <- getLine
    let v1 = take 3 s
    let v2 = take 3 (drop 3 s)
    let x = f v1
    let y = f v2
    if x==y then putStrLn "YES" else putStrLn "NO"
    solve (t-1)

main :: IO()
main = do
    line <- getLine
    let t = (read (takeWhile (/= ' ') line) :: Int)
    solve t