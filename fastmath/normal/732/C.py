a, b, c = map(int, input().split())
ans = 0
x, y, z = max(a, b, c), (a + b + c) - (max(a, b, c) + min(a, b, c)), min(a, b, c)
if x > y:
    ans += x - y - 1
if x > z:
    ans += x - z - 1
print(ans)