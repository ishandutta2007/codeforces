#"Clearing really easy shit", episode 2
import sys
input = sys.stdin.readline

for _ in range(int(input())):
	k, n, a, b = [int(x) for x in input().split()]
	ans = (b * n - k + 1) // (b - a)
 
	print(min(n, ans) if ans >= 0 else -1)