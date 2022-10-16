#!/usr/bin/env python3
#! -*- coding: utf-8 -*-
from collections import Counter


def main():
	n = int(input())
	cnt = Counter(map(int, input().split()))
	for a, val in cnt.items():
		if val % 2 == 1:
			print("Conan")
			exit(0)
	print("Agasa")

if __name__ == '__main__':
	main()