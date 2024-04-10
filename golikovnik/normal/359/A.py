#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	n, m = map(int, input().split())
	a = []
	for _ in range(n):
		a.append([int(i) for i in input().split()])
	ok = 0
	ok |= sum(a[0])
	ok |= sum(a[-1])
	for row in a:
		ok |= row[0] + row[-1]
	print(2 if ok else 4)


if __name__ == '__main__':
	main()