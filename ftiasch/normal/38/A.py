# School Personal Contest #1
# Problem A -- Army
n = int(raw_input())
d = map(int, raw_input().split())
a, b = map(int, raw_input().split())
s = 0
while(a < b):
	s += d[a - 1]
	a += 1
print s