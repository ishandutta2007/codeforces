t = int(input())
 
while t > 0:
    t -= 1
    n, k = input().split()
    n = int(n)
    k = int(k)
    curr = k
    a = [int(x) for x in input().split()]
    for i in range(n):
        x = min(curr, a[i])
        a[i] -= x
        curr -= x
    a[n-1] += k-curr
    print(str(a).replace(",","")[1:-1])