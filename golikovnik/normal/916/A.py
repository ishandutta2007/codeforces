#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	x = int(input())
	h, m = map(int, input().split())
	seconds = m * 60 + h * 60 * 60
	y = 0
	while 1:
		sec = ((seconds - y * x * 60) + (24 * 60 * 60)) % (24 * 60 * 60)
		m = sec // 60 % (60)
		h = sec // 60 // 60
		if '7' in str(m) or '7' in str(h):
			print(y)
			exit(0)
		y += 1


if __name__ == '__main__':
	main()