def read_input():
	return map(int, input().split())

n = int(input())
a = sorted(read_input())

s = sum(a)
i = 0

while 2 * s < 9 * n:
	delta = 5 - a[i]
	s += delta
	i += 1

print(i)