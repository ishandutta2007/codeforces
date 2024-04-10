n, x = map(int,input().split())
ans = 0
for i in range(n):
    s = input()
    d = int(s[2:])
    if s[0] == '+':
        x += d
    else:
        if x < d:
            ans += 1
        else:
            x -= d
print(x,ans)