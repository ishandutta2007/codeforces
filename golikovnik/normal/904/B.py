#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():
	field = []
	for _ in range(3):
		s = input()
		s = s.replace(' ', '')
		field.append(list(s))
	input()
	for _ in range(3):
		s = input()
		s = s.replace(' ', '')
		field.append(list(s))
	input()
	for _ in range(3):
		s = input()
		s = s.replace(' ', '')
		field.append(list(s))
	x, y = map(int, input().split())
	x -= 1
	y -= 1
	x %= 3
	y %= 3
	x *= 3
	y *= 3
	cnt = 0
	for i in range(x, x + 3):
		for j in range(y, y + 3):
			if field[i][j] != '.':
				cnt += 1
	if cnt == 9:
		for i in range(9):
			for j in range(9):
				if field[i][j] == '.':
					field[i][j] = '!'
	else:
		for i in range(x, x + 3):
			for j in range(y, y + 3):
				if field[i][j] == '.':
					field[i][j] = '!'
	for i in range(9):
		print(' '.join([''.join(field[i][:3]), ''.join(field[i][3:6]), ''.join(field[i][6:])]))
		if not (i + 1) % 3 and not i == 8:
			print()



if __name__ == '__main__':
	main()