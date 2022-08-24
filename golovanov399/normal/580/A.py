n = int(raw_input())
a = map(int, raw_input().split())
ans = 0
cur = 0
y = -1488
for x in a:
    if x >= y:
        cur += 1
    else:
        ans = max(ans, cur)
        cur = 1
    y = x
ans = max(ans, cur)
print ans