import sys

#sys.stdin = open('in.txt', 'rt')

n = int(input())
a1 = sorted(map(int, input().split()))
a2 = sorted(map(int, input().split()))
a3 = sorted(map(int, input().split()))

b = []
for i in enumerate(a1):
    if i[0] > n - 2 or i[1] != a2[i[0]]:
        b.append(i[1])
        break
for i in enumerate(a2):
    if i[0] > n - 3 or i[1] != a3[i[0]]:
        b.append(i[1])
        break
print(' '.join(map(str, b)))