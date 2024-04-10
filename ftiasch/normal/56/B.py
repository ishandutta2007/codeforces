# Codeforces Beta Round #52
# Problem B -- Spoilt Permutation
n = int(raw_input())
a = map(int, raw_input().split())

def check():
	for i in xrange(n):
		if a[i] != i + 1:
			return False
	return True

def check2(i, j):
	for k in xrange(i, j + 1):
		if a[k] != j + 1 - (k - i):
			return False
	return True

if check():
	print 0, 0
else:
	i = 0
	while a[i] == i + 1:
		i += 1
	j = n - 1
	while a[j] == j + 1:
		j -= 1
	if check2(i, j):
		print i + 1, j + 1
	else:
		print 0, 0