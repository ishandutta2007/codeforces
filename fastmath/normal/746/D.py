n, k, a, b = map(int, input().split())

f, s = 'G', 'B'
if b > a:
    a, b = b, a
    f, s = s, f
    
if a > (b + 1) * k:
    print('NO')
elif a < k:
    print(f * a + s * b)
else:
    ans = [0] * (n + 1000)
    ans[0] = k
    a -= k
    i = 1
    while a > k:
        b -= 1
        a -= k
        ans[i] = 1
        ans[i + 1] = k
        i += 2
    
    l = i - 1
    if a:
        ans[i] = 1
        ans[i + 1] = a        
        b -= 1
        a = 0
        l += 2
    
    i = 1
    while b > (k - ans[i]):
        b -= (k - ans[i])
        ans[i] = k
        i += 2
        
    ans[i] += b
    l = max(l, i)
    
    for i in range(l + 1):
        if not (i % 2):
            print(f * ans[i], end = '')
        else:
            print(s * ans[i], end = '')