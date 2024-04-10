from math import sqrt
def main(): #this is so hard to make pass lel
    n, m = map(int, input().split())
    ans, cur = 0, 2
    if m >= n:
        ans = n * (m - n)
        m = n - 1
    t = min(int(sqrt(n)) + 1, m)
    while cur <= t:
        ans += n % cur
        cur += 1
    while cur <= m:
        div = n // cur
        nxt = min(n // div, m)
        sub = nxt - cur + 1
        ans += (n % cur) * sub - div * sub * (sub - 1) // 2
        cur = nxt + 1
    print(ans % 1000000007)
 
main()