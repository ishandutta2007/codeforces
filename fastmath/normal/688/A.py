n, d = map(int, input().split())
days = [0]*d
for i in range(d):
    days[i] = input()
k = 0
ans = 0
for i in range(d):
    if '0' in days[i]:
        k += 1
    else:
        if k > ans:
            ans = k
        k = 0
if k > ans:
    ans = k
print(ans)