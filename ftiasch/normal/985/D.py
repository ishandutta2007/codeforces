def solve(H, h):
    if h <= H:
        return (h + 1) * h // 2
    return (H + (h - 1)) * (h - H) // 2 + (h + 1) * h // 2

n, H = map(int, input().split())
# print(n, H)
low = 1
high = n
while low < high:
    middle = (low + high + 1) // 2
    if solve(H, middle) <= n:
        low = middle
    else:
        high = middle - 1
h = low
print(max(h - H, 0) + h + (n - solve(H, h) + (h - 1)) // h)