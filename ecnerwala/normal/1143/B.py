n = int(input())
n += 1
n = str(n)[::-1]
res = 0
for i in range(len(n)):
    if n[i] == '0': continue
    v = '9' * i + chr(ord(n[i])-1) + n[i+1:]
    v = int(v[::-1])
    cnd = 1
    for c in str(v):
        cnd *= int(c)
    res = max(res, cnd)
print(res)