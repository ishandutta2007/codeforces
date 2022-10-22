n = int(input())

ans = 'maybe'
rate = [0] * n
for i in range(n):
    a, b = map(int, input().split())
    rate[i] = [a, b]
    if a != b:
        ans = 'rated'
        
if ans == 'rated':
    print(ans)
else:
    mn = 10 ** 9
    for i in range(n):
        if mn < rate[i][0]:
            ans = 'unrated'
            break
        
        mn = min(mn, rate[i][0])
        
    print(ans)