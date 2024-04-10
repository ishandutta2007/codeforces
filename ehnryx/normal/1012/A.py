n = int(input())
a = [ int(x) for x in input().split() ]
a.sort()

ans = (a[n-1] - a[0]) * (a[2*n-1] - a[n])
for i in range(1, n):
    ans = min(ans, (a[2*n-1] - a[0]) * (a[i+n-1] - a[i]))

print(ans)