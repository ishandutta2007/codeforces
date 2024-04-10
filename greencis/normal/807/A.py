n = int(input())
a = [0 for i in range(n)]
b = [0 for i in range(n)]
ans = "maybe"
for i in range(n):
    a[i], b[i] = map(int, input().split())
    if i > 0 and b[i - 1] < b[i]:
        ans = "unrated"
for i in range(n):
    if a[i] != b[i]:
        ans = "rated"
        break
print(ans)