n = int(input())
a = input()
p1 = 0
p2 = 0
for i in range(n):
    if i % 2 and a[i] != 'r':
        p1 += 1
    if not i % 2 and a[i] != 'b':
        p2 += 1
m1 = max(p1, p2)

p1 = 0
p2 = 0
for i in range(n):
    if i % 2 and a[i] != 'b':
        p1 += 1
    if not i % 2 and a[i] != 'r':
        p2 += 1
m2 = max(p1, p2)

print(min(m1, m2))