n, c1, c2 = map(int, raw_input().split())
s = raw_input()
cnt = s.count('1')

ans = 10 ** 100
for i in xrange(1, cnt + 1):
    cur = c1 * i
    cc = n % i
    cur += c2 * (n // i) ** 2 * cc
    cur += c2 * (n // i - 1) ** 2 * (i - cc)
    ans = min(ans, cur)

print ans