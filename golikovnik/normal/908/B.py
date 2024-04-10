#!/usr/bin/env python3
#! -*- coding: utf-8 -*-
from itertools import permutations


def main():
	n, m = map(int, input().split())
	field = []
	start = (-1, -1)
	end = (-1, -1)
	for i in range(n):
		field.append(input())
		if field[i].find('S') != -1:
			start = i, field[i].find('S')
		if field[i].find('E') != -1:
			end = i, field[i].find('E')
	cmds = [int(i) for i in input()]
	directions = ['D', 'L', 'R', 'U']
	cnt = 0
	for dirs in permutations(directions, 4):
		y, x = start
		fail = False
		ok = False
		for cmd in cmds:
			#print(cmd)
			if dirs[cmd] == 'D':
				y += 1
			elif dirs[cmd] == 'U':
				y -= 1
			elif dirs[cmd] == 'L':
				x -= 1
			else:
				x += 1
			if x < 0 or x >= m or y < 0 or y >= n or field[y][x] == '#':
				fail = True
				break
			if (y, x) == end:
				ok = True
				break
		if fail:
			continue
		if ok:
			cnt += 1
			continue
		if (y, x) == end:
			cnt += (y, x) == end
	print(cnt)



if __name__ == '__main__':
	main()