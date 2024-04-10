teams = [input(), input()]
n = int(input())
cnt = [0]*10000
used = [False]*10000
for i in range(n):
    time, t, m, c = input().split()
    m = int(m)
    if t != 'h':
        m += 1000
    if c == 'y':
        cnt[m] += 1
    else:
        cnt[m] += 2
    if cnt[m] >= 2 and not used[m]:
        used[m] = True
        m %= 1000
        ans = ""
        if t == 'h':
            ans += teams[0]
        else:
            ans += teams[1]
        ans += ' '
        ans = ans + str(m)
        ans += ' '
        ans += time
        print(ans)