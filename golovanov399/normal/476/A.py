n, m = map(int, raw_input().split())

l = (n + 1) // 2
r = n
if (l - 1) // m == r // m:
    print -1
else:
    print ((l - 1) // m + 1) * m