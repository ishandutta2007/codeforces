tests = int(input())
for _ in range(tests):
    n, c0, c1, h = map(int, input().split())
    s = input()
    k0 = sum(1 if c == '0' else 0 for c in s)
    k1 = sum(1 if c == '1' else 0 for c in s)
    ans = 10**18
    for i in range(k0 + 1):
        ans = min(ans, i * h + (k0 - i) * c0 + (k1 + i) * c1)
    for i in range(k1 + 1):
        ans = min(ans, i * h + (k0 + i) * c0 + (k1 - i) * c1)
    print(ans)