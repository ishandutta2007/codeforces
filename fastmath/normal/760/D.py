def go(l, key, plus):
    while t[l + 1] + plus - 1 < key:
        l += 1
    return l


INF = 10 ** 9
n = int(input())

t = [INF] * (n + 1)
t[0] = -INF

c = [0] * (n + 1)
l1 = 0
l2 = 0
for i in range(1, n + 1):
    t[i] = int(input())
    l1 = go(l1, t[i], 90)
    l2 = go(l2, t[i], 1440)
    
    c1 = c[i - 1] + 20
    c2 = c[l1] + 50
    c3 = c[l2] + 120
    c[i] = min(c1, c2, c3)
    print(c[i] - c[i - 1])