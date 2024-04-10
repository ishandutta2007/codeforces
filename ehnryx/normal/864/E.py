from sys import stdin, stdout

n = int(stdin.readline())
items = []
for i in range(n):
  t,d,p = map(int,stdin.readline().split())
  items.append((d,p,t,i+1))
items.sort()

N = 2000+1
dp = [0 for i in range(N)]
cur = [[] for i in range(N)]
for d,p,t,it in items:
  for i in range(d-1,t-1,-1):
    if dp[i-t] + p > dp[i]:
      dp[i] = dp[i-t] + p
      cur[i] = cur[i-t] + [it]

best = 0
for i in range(N):
  if dp[i] > dp[best]:
    best = i

stdout.write('{}\n'.format(dp[best]))
stdout.write('{}\n'.format(len(cur[best])))
stdout.write(' '.join([str(x) for x in cur[best]]) + '\n')