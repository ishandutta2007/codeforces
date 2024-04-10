'''input
3
'''
n = int(input())

def F(n):
	t = 1
	for i in range(n):
		t *= n - i
	return t

def C(n, k):
	t = 1
	for i in range(k):
		t *= n - i
	for i in range(k):
		t //= i + 1
	return t



print(4 * (2 * 3 * int(4 ** (n - 3)) + (n - 3) * 3 * 3 * int(4 ** (n - 4))))