l = list(int(c) for c in str(int(input())))

def prod(l):
    p = 1
    for d in l:
        p *= max(d, 1)
    return p

m = prod(l)
i = len(l) - 1
while i >= 0:
    while i >= 0 and l[i] == 9:
        i -= 1
    if i < 0:
        break
    l[i] = 9
    while i > 0 and l[i - 1] == 0:
        l[i - 1] = 9
        i -= 1
    i -= 1
    if i < 0:
        break
    l[i] = l[i] - 1
    m = max(m, prod(l))

print(m)