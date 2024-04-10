def check(m):
    r = m // time
    t1 = 2 * r * time1 + r * time2
    m %= time
    
    if m < time1:
        t2 = 2 * m
    else:
        t2 = 2 * time1 + (m - time1)
        
    return 2 * t <= t1 + t2


k, d, t = map(int, input().split())

time1 = k
div = (k - 1) // d + 1
time2 = d * div - k
time = time1 + time2

l = 0
r = 10 ** 20
while l < r - 1:
    m = (l + r) // 2
        
    if check(m / 2):
        r = m
    else:
        l = m
            
print(r / 2)