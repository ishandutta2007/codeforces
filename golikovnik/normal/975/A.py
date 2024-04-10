n = int(input())
have = []
for word in input().split():
	root = set(word)
	if root not in have:
		have.append(root)
print(len(have))