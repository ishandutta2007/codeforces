#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from string import ascii_lowercase


def main():
	n = int(input())
	can = set(ascii_lowercase)
	i = -1
	found = False
	cnt = 0
	for j in range(n):
		turn, word = input().split()
		if found and j != n - 1 and turn != '.':
			cnt += 1
		if turn == '.':
			can -= set(word)
			if len(can) == 1 and not found:
				i = j
				found = True
		elif turn == '!':
			can &= set(word) 
			if len(can) == 1 and not found:
				i = j
				found = True				
		else:
			if j == n-1:
				i = n-1
				break
			else:
				can -= set(word)
				if len(can) == 1 and not found:
					i = j
					found = True
	print(cnt)



if __name__ == '__main__':
	main()