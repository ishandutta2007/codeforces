# School Personal Contest #2
# Problem A -- Ball Game
n = int(raw_input())
for i in range(n - 1):
	print ((i + 2) * (i + 1) / 2) % n + 1,