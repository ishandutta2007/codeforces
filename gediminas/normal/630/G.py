'''input
2
'''
n = int(input())

def C(n, k):
	t = 1
	for i in range(k):
		t *= n - i
	for i in range(k):
		t //= i + 1
	return t

print(C(n + 2, 3)*C(n + 4, 5))