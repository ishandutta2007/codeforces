import Control.Applicative
import Text.Printf
 
data Result = Result Double Int Int
 
instance Eq Result where
	Result t1 x1 y1 == Result t2 x2 y2 = t1 == t2 && x1 == x2 && y1 == y2
instance Ord Result where
	Result t1 x1 y1 <= Result t2 x2 y2 = t1 < t2 || t1 == t2 && x1 + y1 > x2 + y2
 
main = do
	ws <- words <$> getLine
	let [t1, t2, _, _, t0] = map read ws
	let [_, _, x1, x2, _] = map read ws
	if t1 == t2
	then
		printf "%d %d" x1 x2
	else
		let
			rs = (Result t2 0 x2) : [Result t y1 y2 | y1 <- [1..x1],
				let y2 = ceiling $ ((fromIntegral y1) * (t0 - t1)) / (t2 - t0),
				y2 <= x2,
				let t = (t1 * (fromIntegral y1) + t2 * (fromIntegral y2)) / fromIntegral (y1 + y2),
				t >= t0]
			(Result _ y1 y2) = minimum rs
		in
		 	 printf "%d %d" y1 y2