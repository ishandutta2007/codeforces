s = input()
t = input()

m, n = len(s), len(t)

took = 0
while took < min(m, n) and s[-took-1] == t[-took-1]:
	took += 1

print(m + n - 2 * took)