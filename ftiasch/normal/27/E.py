# Codeforces Beta Round #27
# Problem E -- Number With The Given Amount Of Divisors
def search(a, n, depth, last):
	global answer
	if (last < 0) or (a > answer):
		return
	if n > 1:
		for i in reversed(range(last)):
			if n % divisor[i] == 0:
				search(a * power[depth][divisor[i] - 1], n / divisor[i], depth + 1, i + 1)
	elif a < answer:
		answer = a

prime = [2, 3, 5, 7, 11, 13, 17, 19, 23]
power = []
for p in prime:
	power.append([p ** i for i in range(64)])

n = int(raw_input())
divisor = []
for i in range(2, 64):
	if n % i == 0:
		divisor.append(i)

answer = 1000000000000000000
search(1, n, 0, len(divisor))
print answer