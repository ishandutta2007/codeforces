r = input
n = int(r())
for _ in range(n):
    a = [*map(int, r().split())]
    print(a[0], a[1], a[-1] - a[0] - a[1])