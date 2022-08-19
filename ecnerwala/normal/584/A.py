n,t = input().split()
n = int(n)
while len(t) < n: t += '0'
print(-1 if len(t) > n else t)