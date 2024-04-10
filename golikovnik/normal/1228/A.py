l, r = map(int, input().split())
for i in range(l, r + 1):
    s = str(i)
    if len(s) == len(set(s)):
        print(i)
        break
else:
    print(-1)