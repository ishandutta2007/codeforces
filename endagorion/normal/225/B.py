def readInt():
    return tuple([int(x) for x in raw_input().split()])

s, k = readInt()
if k >= 40:
    fib = [2**i for i in xrange(40)]
else:
    fib = [0] * (k - 1) + [1]
    while fib[-1] < s:
        fib.append(sum(fib[-k:]))
ans = [0]
while s > 0:
    if fib[-1] <= s:
        ans.append(fib[-1])
        s -= fib[-1]
    fib.pop()
print len(ans)
print " ".join([str(x) for x in ans])