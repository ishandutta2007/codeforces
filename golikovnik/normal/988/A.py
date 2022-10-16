n, k = map(int, input().split())
mp = dict()
for i, score in enumerate(input().split(), 1):
    mp[score] = i
if len(mp) < k:
    print("NO")
else:
    print("YES")
    print(*list(mp.values())[:k])