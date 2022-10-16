x, y, z, t1, t2, t3 = map(int, input().split())
ladder = abs(x - y) * t1
elevator = abs(x - z) * t2 + 3 * t3 + abs(x - y) * t2
if elevator > ladder:
	print("NO")
else:
	print("YES")