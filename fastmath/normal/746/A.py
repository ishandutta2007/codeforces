a = int(input())
b = int(input())
c = int(input())

ans = 0
for i in range(a + 1):
    if b >= i * 2 and c >= i * 4:
        ans = i * 7
print(ans)