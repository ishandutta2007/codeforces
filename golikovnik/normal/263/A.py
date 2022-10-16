#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	x, y = -1, -1
	for i in range(5):
		s = input().split()
		if s.count('1'):
			x = s.index('1') + 1
			y = i + 1
	print(abs(x - 3) + abs(y - 3))



if __name__ == '__main__':
	main()