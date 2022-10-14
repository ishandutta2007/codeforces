n = input()
a = map(int, raw_input().split())
result = 0
for i in xrange(n):
    result += (a[i] - 1) * i + a[i]
print result