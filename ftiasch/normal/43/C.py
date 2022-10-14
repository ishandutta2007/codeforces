# Codeforces Beta Round #42
# Problem C -- Lucky Tickets
n = input()
a = map(int, raw_input().split())
c = [0] * 3
for x in a:
	c[x % 3] += 1
print c[0] / 2 + min(c[1], c[2])