n = int(input())
a = list(map(int, input().split()))

a = sorted(a)
ans = 0
b = [0] * n
for i in range(n):
    if b[i] == 0:
        ans += 1
        for j in range(i, n):
            if a[j] % a[i] == 0:
                b[j] = 1
print(ans)