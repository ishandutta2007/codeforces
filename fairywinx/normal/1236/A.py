t = int(input())
for u in range(t):
    a, b, c = map(int, input().split())
    b1 = 0
    mx = 0
    for i in range(a + 1):
        ans = 0
        if i * 2 > b:
            break
        ans = i * 3
        b1 = b - 2 * i
        ans += min(b1, c // 2) * 3
        mx = max(ans, mx)
    print(mx)