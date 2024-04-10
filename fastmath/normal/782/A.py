n = int(input())
a = list(map(int, input().split()))

now = 0
ans = 0
used = [False] * n
for i in range(2 * n):
    if used[a[i] - 1]:
        now -= 1
    else:
        now += 1
        used[a[i] - 1] = True
        
    ans = max(ans, now)
    
print(ans)