#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	n = int(input())
	a = [int(i) for i in input().split()]
	ans = [[], [], []]
	neg = sum(x < 0 for x in a)
	flag = 0
	for x in a:
		if x > 0:
			ans[1].append(x)
		elif x == 0:
			ans[2].append(x)
		else:
			if neg % 2 == 0 and not flag:
				ans[2].append(x)
				flag = 1
			else:
				ans[0].append(x)
	if not ans[1]:
		assert len(ans[0]) >= 2
		ans[1].extend(ans[0][:2])
		ans[0] = ans[0][2:]
	for arr in ans:
		print(len(arr), *arr)


if __name__ == '__main__':
	main()