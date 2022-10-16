#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	s, t = input().split()
	minimal = ""
	for i in range(len(s) + 1):
		for j in range(len(t) + 1):
			if not i or not j:
				continue
			else:
				pref = s[:i] + t[:j]
				minimal = pref if not minimal else min(minimal, pref)
	print(minimal)



if __name__ == '__main__':
	main()