#!/usr/bin/env python3
#! -*- coding: utf-8 -*-
from sys import stdin, stdout

def main():
	input = stdin.readline
	print = stdout.write
	n, m = map(int, input().split())
	a = [int(i) for i in input().split()]
	pos = sum(x > 0 for x in a)
	neg = n - pos
	for _ in range(m):
		L, R = map(int, input().split())
		length = R - L + 1
		if length % 2 == 0 and pos >= length // 2 and neg >= length // 2:
			print('1\n')
		else:
			print('0\n')


if __name__ == '__main__':
	main()