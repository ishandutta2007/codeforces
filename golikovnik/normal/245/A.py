n = int(input())
success = [0, 0]
total = [0, 0]
for _ in range(n):
	i, x, y = map(int, input().split())
	total[i-1] += 10
	success[i-1] += x
for i in range(2):
	print("LIVE" if success[i] * 2 >= total[i] else "DEAD")