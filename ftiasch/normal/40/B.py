# Codeforces Beta Round #40
# Problem B -- Repaintings
n, m = map(int, raw_input().split())
x = input() - 1
if min(n, m) > 2 * x:
	print max(n + m - 4 * x - 2, 1)
else:
	print 0