n, t = map(int, input().split())
ans = 10 ** (n - 1)
upper = 10 ** n
while ans < upper:
    if ans % t == 0:
        print(ans)
        break
    ans += 1
if ans == upper:
    print(-1)