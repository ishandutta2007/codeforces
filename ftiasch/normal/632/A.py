n, p = map(int, input().split())
a = []
for i in range(n):
    a.append(input())
total, count = 0, 0
for a in reversed(a):
    if (len(a) == 4):
        total = total * 2
    else:
        total = total * 2+1
        count = count + 1
print(total * p - count * (p // 2))