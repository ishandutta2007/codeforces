#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():
	n, d = map(int, input().split())
	s = input()
	i = 0
	cnt = 0
	while 1:
		maxi = i + d
		if maxi >= n - 1:
			cnt += 1
			break
		found = False
		for j in range(maxi, i, -1):
			if s[j] != '0':
				i = j
				cnt += 1
				found = True
				break
		if not found:
			print(-1)
			exit()
	print(cnt)


if __name__ == '__main__':
	main()