a, b, c = map(int, input().split())
N = max(a, b, c)
mod = 998244353

def mul(a, b):
	return (a * b) % mod

from itertools import accumulate

fact = [1] + list(accumulate(range(1, N + 1), mul))
rfact = [0] * (N + 1)
rfact[-1] = pow(fact[-1], mod - 2, mod)
for i in range(N - 1, -1, -1):
	rfact[i] = mul(rfact[i + 1], i + 1)

def C(n, k):
	return mul(mul(fact[n], rfact[k]), rfact[n - k])

def get(x, y):
	ans = 0
	for n in range(min(x, y) + 1):
		ans += mul(
			mul(C(x, n), C(y, n)), fact[n])
	return ans

print(mul(
	mul(get(a, b), get(a, c)), get(b, c)))