t = int(input())
for i in range(t):
    n,k = input().split()
    n = int(n)
    k = int(k)
    print(pow(n,k,1000000007))