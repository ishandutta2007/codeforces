#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	square = []
	INF = int(1e5)
	for _ in range(3):
		square.append([int(i) for i in input().split()])
	for first in range(1, INF + 1):
		s = first + square[0][1] + square[0][2]
		second = s - square[1][0] - square[1][2]
		third = s - square[2][0] - square[2][1]
		square[0][0] = first
		square[1][1] = second
		square[2][2] = third
		if second <= 0 or third <= 0 or second > INF or third > INF:
			continue
		if square[0][0] + square[1][0] + square[2][0] == square[0][1] + square[1][1] + square[2][1] == square[0][2] + square[1][2] + square[2][2] == square[2][0] + square[1][1] + square[0][2] == square[0][0] + square[1][1] + square[2][2] == s:
			print(*square[0])
			print(*square[1])
			print(*square[2])
			break
		square[0][0] = square[1][1] = square[2][2] = 0


if __name__ == '__main__':
	main()