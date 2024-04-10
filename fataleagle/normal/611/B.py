a, b = map(long, raw_input().split())
ans = 0
for i in xrange(1, 70):
    for j in xrange(70):
        s = '1' * i + '0' + '1' * j
        if a <= long(s, 2) <= b:
            ans += 1
print ans