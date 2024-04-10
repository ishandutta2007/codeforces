h, n = map(int, input().split())
ans = h
n = n - 1 + (1 << h)
for i in range(1, h+1):
    if not ( ((n & (1 << i)) == 0) ^ (n & (1 << (i-1)) == 0 )):
        ans += (1 << i) - 1
print(ans)