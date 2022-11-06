l = int(input())
s = input()

best = 0
best2 = None
for sl in range(1, l):
    if s[sl] != '0':
        if max(sl, l - sl) < max(best, l - best):
            best = sl
            best2 = None
        elif max(sl, l - sl) == max(best, l - best):
            best2 = sl

f = s[:best]
b = s[best:]

res = int(s[:best]) + int(s[best:])
if best2 is None:
    print(res)
else:
    res2 = int(s[:best2]) + int(s[best2:])
    print(min(res, res2))