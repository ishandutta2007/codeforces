a = input()
d = list()
for i in range(0, 10):
    d.append(str(i))

for i in ('A', 'B', 'C', 'D', 'E', 'F'):
    d.append(i)

cur = int(0)
l = len(a)

for i in range(0, l):
    for j in range(0, 16):
        if (a[i] == d[j]):
            cur = cur * 16
            cur += j

print(cur&1)