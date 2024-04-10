from collections import Counter

def no():
	print("No")
	exit(0)

s = input()
if len(s) < 4:
	no()
cnt = Counter(s)
cnt = list(cnt.items())
if len(cnt) < 2 or len(cnt) > 4:
	no()
if len(cnt) == 2 and (cnt[0][1] == 1 or cnt[1][1] == 1):
	no()
if len(cnt) == 3 and (max(cnt[0][1], cnt[1][1], cnt[2][1]) == 1):
	no()
print("Yes")