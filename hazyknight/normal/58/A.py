n = input()
match = ['h','e','l','l','o']
p = 0
for i in range(len(n)):
	if p < 5 and n[i] == match[p]:
		p += 1
if p == 5:
	print("YES")
else:
	print("NO")