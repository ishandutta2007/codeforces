#!/usr/bin/env python3
#! -*- coding: utf-8 -*-
from math import sqrt, ceil


def is_prime(n):
	if n == 1:
		return False
	for i in range(2, int(ceil(sqrt(n))) + 1):
		if n % i == 0:
			return False
	return True

def main():
	INF = int(1e9)
	n, m = map(int, input().split())
	edges = n - 1
	closest_prime = edges
	while not is_prime(closest_prime):
		closest_prime += 1
	average = closest_prime // edges
	print(closest_prime, closest_prime)
	for i in range(edges):
		if i == edges - 1:
			print(i + 1, i + 2, closest_prime)
			continue
		print(i + 1, i + 2, average)
		closest_prime -= average
	m -= edges
	for i in range(n):
		for j in range(i + 2, n):
			if not m:
				break
			print(i + 1, j + 1, INF)
			m -= 1
		if not m:
			break


if __name__ == '__main__':
	main()