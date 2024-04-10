#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	table = []
	for _ in range(8):
		table.append(input())
	for i in range(8):
		whites = table[i].count('W')
		blacks = 8 - whites
		if whites != 4:
			print("NO")
			return
		for j in range(8):
			if table[i][j] == table[i][(j + 1) % 8]:
				print("NO")
				return
	print("YES")


if __name__ == '__main__':
	main()