def gcd(a, b):
    while b:
        a, b = b, a % b
        
    return a


n = int(input())

a = list(map(int, input().split()))
ans = 0
l = 0

g = a[0]
for i in range(n):
    g = gcd(a[i], g)
    
if g > 1:
    print('YES\n0')
else:
    for i in range(n):
        if a[i] % 2:
            l += 1
        else:
            if l % 2:
                ans += l // 2 + 2
            else:
                ans += l // 2
            
            l = 0
            
    if l % 2:
        ans += l // 2 + 2
    else:
        ans += l // 2
    
    print('YES')
    print(ans)