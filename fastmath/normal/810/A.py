def check(m):
    return (s + k * m) * 2 >= (2 * k - 1) * (n + m)


n, k = map(int,input().split())
a = list(map(int, input().split()))

s = sum(a)
l = -1
r = 10 ** 6
while l < r - 1:
    m = (l + r) // 2
    if check(m):
        r = m
    else:
        l = m
        
print(r)