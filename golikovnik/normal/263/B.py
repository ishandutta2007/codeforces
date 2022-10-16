#!/usr/bin/env python3
#! -*- coding: utf-8 -*-


def main():
	n, k = map(int, input().split())
	a = [int(i) for i in input().split()]
	if k > n:
		print(-1)
		return
	a.sort()
	print(0, a[n - k])


if __name__ == '__main__':
	main()