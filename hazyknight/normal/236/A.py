s = input()
count = [0 for i in range(26)]
cnt = 0
for i in range(len(s)):
	count[ord(s[i]) - ord('a')] += 1
for i in range(26):
	if count[i] > 0:
		cnt += 1
if cnt % 2 == 1:
	print("IGNORE HIM!")
else:
	print("CHAT WITH HER!")