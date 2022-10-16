a, b, x = map(int, input().split())

first = int(a < b)
ans = []

for i in range(x + 1):
	ans.append(str(first ^ (i & 1)))

ans[0] += str(first) * (max(a, b) - x - 1 + (x + 1) // 2)
ans[1] += str(first ^ 1) * (min(a, b) - (x + 1) // 2)

print(''.join(ans))