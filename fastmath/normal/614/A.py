l, r, k = map(int, input().split())
cur = 1
ans = []
while cur <= r:
    if cur >= l:
        ans.append(cur)
    cur *= k
if len(ans) == 0:
    print(-1)
else:   
    print(*ans)