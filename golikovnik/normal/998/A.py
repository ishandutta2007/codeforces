n = int(input())
a = [int(x) for x in input().split()]

if n < 2 or n == 2 and a[0] == a[1]:
	print(-1)
	exit()

from operator import itemgetter

print(1)
print(min(enumerate(a), key=itemgetter(1))[0] + 1)