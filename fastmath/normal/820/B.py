n, a = map(int, input().split())

alf = 180 * (n - 2) / n

alf1 = 0
ans = 10 ** 9
ans_v = 0
for i in range(n - 2):
    alf1 += alf / (n - 2)
    
    if abs(alf1 - a) < ans:
        ans = abs(alf1 - a)
        ans_v = n - i
        
print(1, 2, ans_v)