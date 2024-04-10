input()
a = list(map(int, input().split(' ')))
su = a[-1]
l = su
for i in reversed(a[:-1]):
    if l == 0:
        break
    next = min(i, l - 1)
    l = next
    su += next
print(su)