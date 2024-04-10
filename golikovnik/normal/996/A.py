
n = int(input())
money = [100, 20, 10, 5, 1]
ans = 0

for val in money:
	ans += (n // val)
	n %= val

print(ans)