def solve(n, m):
    ans = 0
    for i in range(31,-1,-1):
        nn = n | ((1<<i)-1)
        nn ^= ans
        if nn <= m: ans += 1<<i
    return ans

for i in range(int(input())):
    a,b=map(int,input().split())
    print(solve(a,b))