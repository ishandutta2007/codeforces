N, k = [int(x) for x in raw_input().split()]
a = [0] + [1] * (N - 1)
for i in xrange(k):
    ans = [0] * N
    for j in xrange(N):
        if a[j] < j and (a[j] & (1 << i)) != (j & (1 << i)):
            ans[j] = (1 << i)
            a[j] += (1 << i)
        else:
            ans[j] = 0
    ans.reverse()
    print " ".join([str(N - x) for x in ans])