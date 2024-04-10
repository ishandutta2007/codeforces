#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	n = int(input())
	m = int(input())
	if n <= 27:
		print(m % (1 << n))
	else:
		print(m)


if __name__ == '__main__':
	main()