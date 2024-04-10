n, l, r = map(int, input().split())

a = list(map(int, input().split()))
p = list(map(int, input().split()))

seg = [0] * n
for i in range(n):
    seg[i] = [l - a[i], r - a[i]]
    
segments = [0] * n
for i in range(n):
    segments[p[i] - 1] = seg[i]

c = [0] * n
can = True
l = -(10 ** 18)
for i in range(n):
    if l >= segments[i][1]:
        can = False
        break
    
    if segments[i][0] > l:
        l = segments[i][0]
    else:
        l = l + 1
    
    c[i] = l
    
if not can:
    print(-1)
else:
    for i in range(n):
        print(c[p[i] - 1] + a[i], end = ' ')