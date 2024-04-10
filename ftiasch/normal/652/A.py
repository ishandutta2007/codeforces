def solve(h1, h2, a, b):
    d = max(h2 - a * 8 - h1, 0)
    if d and a <= b:
        return -1
    x = max(1, (a - b) * 12)
    return (d + x - 1) // x


h1, h2 = map(int, input().split())
a, b = map(int, input().split())
print(solve(h1, h2, a, b))