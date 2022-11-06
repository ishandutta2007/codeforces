n, x = map(int, input().split())
t = 1
w = 0
for _ in range(n):
    l, r = map(int, input().split())
    w += (l - t) % x + (r - l + 1)
    t = r + 1
print(w)