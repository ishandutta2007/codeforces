n = int(input())
k = 1
while n:
    n -= 1
    k += k
    if k == 8192:
        k -= 100
print(k)