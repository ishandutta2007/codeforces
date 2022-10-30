n, k = map(int, input().split())
ans = []
for a, b in sorted(zip(map(int, input().split()), range(1, n+1))):
    if k >= a:
        k -= a
        ans.append(b)
print(len(ans))
print(' '.join(map(str, ans)))