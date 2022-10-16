a = [int(x) - 1 for x in input().split()]
n = m = 48
colors = "ABCD"
side = n // 2
ans = [[0] * n for _ in range(n)]
for i, color in enumerate(colors):
	for dx in range(side):
		for dy in range(side):
			x, y = dx + side * (i & 1), dy + side * (i // 2)
			ans[x][y] = color
			new_i = (i + 1) % 4
			if 0 < min(dx, dy) and max(dx, dy) < side - 1 and a[new_i] and dx & 1 and dy & 1:
				ans[x][y] = colors[new_i]
				a[new_i] -= 1
print(n, m)
print(*(''.join(row) for row in ans), sep='\n')