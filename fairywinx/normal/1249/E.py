n, c = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = [0] * n
for i in range(n):
    ans[i] = [0,0]
ans[0][0] = 0
ans[0][1] = c
 
for i in range(1, n):
    
    ans[i][0] = min(ans[i - 1][0] + a[i - 1], ans[i - 1][1] + a[i - 1])
    ans[i][1] = min(ans[i - 1][0] + c + b[i - 1], ans[i - 1][1] + b[i - 1])
for i in range(n):
    print(min(ans[i][0], ans[i][1]), end = ' ')