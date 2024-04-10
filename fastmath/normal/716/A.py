n, c = map(int, input().split())
a = list(map(int,input().split()))
ans = 0
last = 0
for i in range(n):
    if a[i] - last > c:
        ans = 0
    ans += 1
    last = a[i]
print(ans)