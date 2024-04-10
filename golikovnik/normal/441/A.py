#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	n, v = map(int, input().split())
	res = []
	for i in range(n):
		costs = [int(i) for i in input().split()][1:]
		costs.sort()
		if costs[0] < v:
			res.append(i + 1)
	print(len(res))
	print(*res)


if __name__ == '__main__':
	main()