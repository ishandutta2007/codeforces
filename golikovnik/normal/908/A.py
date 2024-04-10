#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	s = input()
	cnt = 0
	vowels = 'aeiou'
	for c in s:
		if c.isdigit():
			cnt += int(c) % 2
		else:
			cnt += c in vowels
	print(cnt)


if __name__ == '__main__':
	main()