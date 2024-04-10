def vis(k):
    if k%400 == 0:
        return True
    if k%4 == 0 and k%100 != 0:
        return True
    return False


n = int(input())
v = vis(n)
if v == True:
    s = 366
else:
    s = 365
i = n + 1
while (s%7 != 0) or vis(i) != v:
    s += 365
    if vis(i):
        s += 1
    i += 1
print(i)