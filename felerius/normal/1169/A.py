n, a, x, b, y = map(int, input().split())
a -= 1
x -= 1
b -= 1
y -= 1

daniel = []
vlad = []
i = a
while i != x:
    daniel.append(i)
    i = (i + 1) % n
daniel.append(x)
i = b
while i != y:
    vlad.append(i)
    i = (i - 1 + n) % n
vlad.append(y)

if any(u == v for u, v in zip(daniel, vlad)):
    print('YES')
else:
    print('NO')