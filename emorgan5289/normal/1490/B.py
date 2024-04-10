for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split(' ')))
    f = [-n//3]*3
    for x in a:
        f[x%3] += 1
    ans = 0
    for i in [0, 1, 2, 0]:
        if f[i] > 0:
            ans += f[i]
            f[(i+1)%3] += f[i]
            f[i] = 0
    print(ans)