n = int(input())
a = list(map(int, input().split()))
mx = max(a)
mn = min(a)
ans = n
for i in range(n):
    if a[i] == mx or a[i] == mn:
        ans -= 1
print(ans)