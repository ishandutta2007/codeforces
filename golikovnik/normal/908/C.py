#!/usr/bin/env python3
#! -*- coding: utf-8 -*-
from math import sqrt


def main():
	n, r = map(int, input().split())
	coords = [(int(i), 1e9) for i in input().split()]
	for i, val in enumerate(coords):
		x, y = val
		if not i:
			coords[i] = x, r
			continue
		candidates = coords[:i]
		ymax = -1
		for xx, yy in candidates:
			if 4 * r ** 2 - (x - xx) ** 2 < 0:
				continue
			y1 = sqrt(4 * r ** 2 - (x - xx) ** 2) + yy
			y2 = yy - sqrt(4 * r ** 2 - (x - xx) ** 2)
			if y1 > ymax and r <= y1 <= y:
				ymax = y1
			if y2 > ymax and r <= y2 <= y:
				ymax = y2
		if ymax == -1:
			ymax = r
		coords[i] = x, ymax
	for xx, yy in coords:
		print(yy, end=' ')


if __name__ == '__main__':
	main()