from math import factorial
def ncr(n, r):
    ans = 1
    for i in range(r):
        ans*=n-i
    for i in range(r):
        ans//=i+1
    return ans

n,k = map(int, input().split())
inp = list(map(int,input().split()))
nz = 0
seq = []
for i in range(n):
    if(inp[i]!=0):
        nz = 1
    if(nz!=0):
        seq.append(inp[i])

if(max(seq) >= k):
    print("0")
    exit(0)

if(len(seq) <= 8):
    seq.reverse()
    mn = 1
    mx = pow(10,18)
    while(mn < mx):
        mid = (mn + mx)//2
        curr = 0
        for i in range(len(seq)):
            curr+=seq[i]*ncr(mid+i-1, i)
        if(curr>=k):
            mx = mid
        else:
            mn = mid + 1
    print(mn)
    exit(0)
for i in range(1000):
    for j in range(1,len(seq)):
        seq[j]+=seq[j-1]
    if(max(seq) >= k):
        print(i+1)
        exit(0)