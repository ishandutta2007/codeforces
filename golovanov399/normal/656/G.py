n, m, t = map(int, input().split())
a = [input() for i in range(n)]
cnt = 0
for j in range(m):
  if [a[i][j] for i in range(n)].count('Y') >= t:
    cnt += 1
print(cnt)#kitten