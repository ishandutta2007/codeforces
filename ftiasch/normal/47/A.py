# Codeforces Beta Round #44
# Problem A -- Triangular numbers
n = int(raw_input())

def check(n):
	for i in xrange(0, 500):
		if i * (i + 1) / 2 == n:
			return True
	return False

print check(n) and "YES" or "NO"