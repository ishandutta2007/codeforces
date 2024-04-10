a, b, c = map(int, input().split())
a %= b

k = 0
for i in range(1000):
    cf = 0
    while (cf < 9 and (k * 10 + cf + 1) * b <= a * 10):
        cf += 1
    
    if cf == c:
        print(i + 1)
        exit(0)
        
    k = k * 10 + cf
    a *= 10
        
        
print(-1)