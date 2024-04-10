n = int(input())

a = [int(i) for i in input().split()]
c = [0, 0]
for i in range(n):
  c[a[i] - 1] += 1

ans = min(c[0], c[1])
c[0] -= ans
c[1] -= ans
ans += c[0] // 3
print(ans)