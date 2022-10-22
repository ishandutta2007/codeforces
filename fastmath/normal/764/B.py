n = int(input())
a = list(map(int, input().split()))

p = 1
r = (n - 1) // 2 + 1
for i in range(r):
    if p % 2:
        a[i], a[-i - 1] = a[-i - 1], a[i]
    p += 1
    
print(' '.join(map(str, a)))