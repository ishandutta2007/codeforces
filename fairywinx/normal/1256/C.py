def gcd(a, b):
    if a == 0:
        return b
    else:
        return gcd(b % a, a)
 
 
n, m, d = map(int, input().split())
 
a = list(map(int, input().split()))
j = 0
p = m - 1
k = [0] * n
for i in range(n - 1, -1, -1):
    k[i] = p + 1
    j += 1
    if a[p] <= j:
        j = 0
        p -= 1
        if p == -1:
            break
    
z = 0

last = -1
for i in range(n):
    if k[i] == 1:
        last = i
    if i - last >= d and k[i] == 0:
        #print(i, last, k, z, a[z] + i, a[z])
        for j in range(0, n):
            if k[j] == z + 1:
                k[j] = 0
        for j in range(i, a[z] + i):
            k[j] = z + 1
            last = j
        z += 1
        #print(z, k)
        if z == m and n - last > d:
            print('NO')
            exit(0)
if d > n:
    print('YES')
    print('1 ' * a[z] + '0 ' * (n - a[z]))
    exit(0)
print('YES')
print(*k)