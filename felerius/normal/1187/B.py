n = int(input())
s = input()
idx = []
for _ in range(26):
    idx.append([])
for i, c in enumerate(s):
    idx[ord(c) - ord('a')].append(i)

m = int(input())
for _ in range(m):
    t = input()
    counts = [0] * 26
    for c in t:
        counts[ord(c) - ord('a')] += 1
    pref = 0
    for i, co in enumerate(counts):
        if co > 0:
            pref = max(pref, idx[i][co - 1])
    print(pref + 1)