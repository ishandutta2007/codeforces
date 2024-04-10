n = int(input())
a = sorted(list(map(int, input().split())))
for i in range(n - 2):
	if a[i] + a[i + 1] > a[i + 2]:
		print("YES")
		exit(0)
print("NO")