def gao(a, b):
	if b == 0:
		return 0
	return gao(b, a%b) + a // b


n, m = list(map(int, input().split()))
print(gao(n, m))