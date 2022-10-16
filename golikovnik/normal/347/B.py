n = int(input())
a = [int(i) for i in input().split()]
have = sum(a[x] == x for x in range(n))
ans = have
for i in range(n):
    if i == a[i] or a[i] == a[a[i]]: continue
    ans = max(ans, have + 1)
    if a[a[i]] == i:
        ans = max(ans, have + 2)
print(ans)