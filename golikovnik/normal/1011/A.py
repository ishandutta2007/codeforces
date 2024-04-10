import itertools
import collections
import sys
import math

input = sys.stdin.readline
read = lambda: input().rstrip()
puts = sys.stdout.write


def read_ints():
	yield from map(int, read().split())


def main():
	n, k = read_ints()
	s = sorted(read())
	cnt = 0
	ans = 0
	last_taken = -1
	for i, c in enumerate(s):
		if cnt == k: break
		if not i or ord(c) - ord(s[last_taken]) >= 2:
			cnt += 1
			last_taken = i
			ans += ord(c) - ord('a') + 1
	print(-1 if cnt < k else ans)

if __name__ == '__main__':
	main()