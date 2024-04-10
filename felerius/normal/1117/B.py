n, m, k = map(int, input().split())
a = list(sorted(map(int, input().split())))
x = a[-1]
y = a[-2]
b = int(m / (k + 1))
print(b * y + (m - b) * x)