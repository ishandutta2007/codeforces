n, a, b, c = map(int, raw_input().split())
ans = float("inf")
for x in xrange(4):
    for y in xrange(4):
        for z in xrange(4):
            if (n + 1 * x + 2 * y + 3 * z) % 4 == 0:
                ans = min(ans, x * a + y * b + z * c)
print ans