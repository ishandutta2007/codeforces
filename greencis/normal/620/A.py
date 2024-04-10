a, b = map(int, input().split())
x, y = map(int, input().split())
print(max(abs(a - x), abs(b - y)))