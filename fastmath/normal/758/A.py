n = int(input())
a = list(map(int, input().split()))

ans = 0
m = max(a)
for elem in a:
    ans += m - elem
    
print(ans)