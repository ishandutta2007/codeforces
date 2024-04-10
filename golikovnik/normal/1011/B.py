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
	n, m = read_ints()
	a = collections.Counter(read_ints())
	ans = 0
	for days in range(1, m+1):
		can = 0
		for k, v in a.items():
			can += v // days
		if can >= n:
			ans = days
	print(ans)


if __name__ == '__main__':
	main()