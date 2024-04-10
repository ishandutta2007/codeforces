# Codeforces Beta Round #39
# Problem A -- Find Color
x, y = map(int, raw_input().split())
r = int((x * x + y * y) ** 0.5)
if x * x + y * y == r * r or (r + (x > 0) + (y > 0)) % 2 == 0:
	print "black"
else:
	print "white"