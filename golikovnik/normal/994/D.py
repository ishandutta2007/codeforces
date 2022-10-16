# your code goes here

n, m = map(int, input().split())

def split2(iterable):
	args = [iter(iterable)] * 2
	return zip(*args)

a = list(split2(map(int, input().split())))
b = list(split2(map(int, input().split())))

can = set()

for x in a:
	for y in b:
		intersections = set(x) & set(y)
		if len(intersections) in [0, 2]:
			continue
		can.update(intersections)

if len(can) == 1:
	print(next(iter(can)))
	exit()

fail = 0

for x in a:
	st = set()
	for y in b:
		intersections = set(x) & set(y)
		if len(intersections) in [0, 2]:
			continue
		st.update(intersections)
	fail |= len(st) > 1

for x in b:
	st = set()
	for y in a:
		intersections = set(x) & set(y)
		if len(intersections) in [0, 2]:
			continue
		st.update(intersections)
	fail |= len(st) > 1

print(-1 if fail else 0)