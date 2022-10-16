n = int(input())
a = [int(x) for x in input().split()]

ones = []
for i, x in enumerate(a):
	if x == 1:
		ones.append(i)

ones.append(n)

print(len(ones) - 1)
print(*[y - x for x, y in zip(ones, ones[1:])])