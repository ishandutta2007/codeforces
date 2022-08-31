n = int(input())
c = 10 ** 10
res = 0
for i in range(n):
 a,p = map(int, input().split())
 c = min(c,p)
 res += c * a
print(res)