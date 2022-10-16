from collections import defaultdict

_, s = input(), input()
cnt = defaultdict(int)
for i in range(len(s) - 1):
	cnt[s[i] + s[i + 1]] += 1
print(max(cnt.items(), key=lambda x: x[1])[0])