def ask(x, y):
	print(x, y, flush=True)
	color = input()
	return color == 'white'

n = int(input())
pts = [[], []]
H = 10
start = ask(0, H)
pts[0].append(0)
n -= 1
MAX = int(1e9)
while n:
	x = (pts[0][-1] + (pts[1][-1] if pts[1] else MAX)) // 2
	clr = ask(x, H)
	clr ^= start
	pts[clr].append(x)
	n -= 1
xl = pts[0][-1]
xr = pts[1][-1] if pts[1] else MAX
print(xl, H - 1, xr, H + 1)