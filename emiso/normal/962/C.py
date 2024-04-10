n = raw_input()

def sq(x):
	y = int(round(x ** 0.5))
	return y * y == x

def solve(idx, st):
	if idx == len(n):
		if len(st) == 0 or st[0] == '0':
			return 99999
		if not sq(int(st)):
			return 99999
		return 0
		
	return min(solve(idx + 1, st) + 1, solve(idx + 1, st + n[idx]))

x = solve(0, "")
print "-1" if x == 99999 else x