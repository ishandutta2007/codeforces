n, k = map(int, input().split())
s = input()
t = s[:k]
ans = t
for i in range(k, n):
    ans += ans[i - k]
if ans >= s:
    print(len(ans))
    print(ans)
else:
    t = s[:k]
    t = str(int(t) + 1)
    ans = t
    for i in range(k, n):
        ans += ans[i - k]
    print(len(ans))
    print(ans)