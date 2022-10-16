# your code goes here

def split2(iterable):
	args = [iter(iterable)] * 2
	return zip(*args)

def read_square():
	tmp = []
	for x, y in split2(input().split()):
		tmp.append((int(x), int(y)))	
	return tmp

a, b = read_square(), read_square()

a.sort()
b.sort()

def inside_rho(A, sq):
	doubleside = sq[-1][0] - sq[0][0]
	aa, bb = sq[1][0], sq[0][1]
	return 2 * abs(A[0] - aa) + 2 * abs(A[1] - bb) <= doubleside

def inside_sq(A, sq):
	x0, x1 = sq[0][0], sq[-1][0]
	y0, y1 = sq[0][1], sq[1][1]
	return x0 <= A[0] <= x1 and y0 <= A[1] <= y1
	
def fit(x, y):
	return inside_rho((x, y), b) and inside_sq((x, y), a)

ok = any(fit(i, j) for i in range(-200, 201) for j in range(-200, 201))

print("YES" if ok else "NO")