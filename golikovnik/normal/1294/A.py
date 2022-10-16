t = int(input())
for _ in range(t):
    a, b, c, n = map(int, input().split())
    a, b, c = sorted([a, b, c])
    need = 2 * c - b - a
    print("YES" if n >= need and n % 3 == need % 3 else "NO")