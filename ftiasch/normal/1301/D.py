n, m, k = map(int, input().split())

steps = []
if m > 1:
    steps.append((m - 1, 'R'))
    steps.append((m - 1, 'L'))
for i in range(n - 1):
    steps.append((1, 'D'))
    if m > 1:
        steps.append((m - 1, 'R'))
        steps.append((m - 1, 'UDL'))
if n > 1:
    steps.append((n - 1, 'U'))

i = 0
while i < len(steps) and steps[i][0] * len(steps[i][1]) < k:
    k -= steps[i][0] * len(steps[i][1])
    i += 1
if i == len(steps):
    print('NO')
else:
    s = steps[i][1]
    steps = steps[:i]
    if k >= len(s):
        steps.append((k // len(s), s))
    if k % len(s) != 0:
        steps.append((1, s[:k % len(s)]))
    print('YES')
    print(len(steps))
    for c, s in steps:
        print(c, s)