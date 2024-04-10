n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(n):
    b.append([a[i], i])
b = sorted(b)[::-1]
ans = 0
for i in range(n):
    ans += i * b[i][0] + 1
    a[i] = b[i][1] + 1
print(ans)
print(*a)