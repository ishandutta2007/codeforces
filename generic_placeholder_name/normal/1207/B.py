#"Clearing really easy shit", episode 7
import sys
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]
a = []
b = [[0] * m for j in range(n)]
ans = []

for i in range(n):
    a.append([int(x) for x in input().split()])
    
for x in range(n-1):
    for y in range(m-1):
        if a[x][y] == a[x][y + 1] == a[x + 1][y] == a[x + 1][y + 1] == 1:
            b[x][y] = 1
            b[x][y+1] = 1
            b[x+1][y] = 1
            b[x+1][y+1] = 1
            ans.append(str(x+1) + ' ' + str(y+1))

if a == b:
    print(len(ans))
    for i in ans:
        print(i)
else:
    print(-1)