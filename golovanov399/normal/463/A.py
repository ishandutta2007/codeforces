ID = input().split()
n = int(ID[0])
s = int(ID[1]) * 100
ans = -1
for i in range(n):
    ID = input().split()
    x = 100 * int(ID[0]) + int(ID[1])
    if (x <= s) and (s - x) % 100 > ans:
        ans = (s - x) % 100

print(ans)