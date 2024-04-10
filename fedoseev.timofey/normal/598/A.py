t = int(input())
for i in range(t):
    n = int(input())
    res = ((n + 1) * n) // 2
    cur_t = 1
    while cur_t <= n:
        res -= 2 * cur_t
        cur_t *= 2
    print(res)