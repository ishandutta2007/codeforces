n = int(input())
a = list(map(int, input().split()))
a = sorted(a)
b = [0] * (n - 1)
for i in range(n - 1):
    b[i] = a[i + 1] - a[i]
nd = b[0]
def nod(a, b):
    if b == 0:
        return a
    else:
        return nod(b, a % b)

for i in range(1, n - 1):
    nd = nod(nd, b[i])
    #print(nd)
ans = 0
for i in range(n):
    ans += (a[-1] - a[i]) // nd
print(ans, nd)
#print(a, b)