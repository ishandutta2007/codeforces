m, day = map(int, input().split())

g = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
print((g[m - 1] - 1 - (7 - day + 1)) // 7 + 2)