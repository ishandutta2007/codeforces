n = int(input())
ax, ay = map(int, input().split())
bx, by = map(int, input().split())
cx, cy = map(int, input().split())
bx -= ax
cx -= ax
by -= ay
cy -= ay
if bx * cx <= 0 or by * cy <= 0:
	print("NO")
else:
	print("YES")