n = int(input())
a = list(map(int, input().split()))

f = 0
for i in range(n):
    if a[i] >= 0:
        f += a[i]

if f % 2:
    print(f)
else:
    m = 10 ** 9
    for i in range(n):
        if a[i] % 2:
            m = min(m, abs(a[i]))
            
    print(f - m)