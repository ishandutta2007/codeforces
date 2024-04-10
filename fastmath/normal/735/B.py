n, n1, n2 = map(int, input().split())
a = list(map(int, input().split()))

if n1 > n2:
    n1, n2 = n2, n1

a.sort(reverse = True)
s1 = 0
for i in range(n1):
    s1 += a[i]

s2 = 0
for i in range(n1, n1 + n2):
    s2 += a[i]
    
print(s1 / n1 + s2 / n2)