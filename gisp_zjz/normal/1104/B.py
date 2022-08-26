s = []
a = 0
for ch in input() :
    if len(s) and s[-1] == ch :
        s.pop()
        a += 1
    else :
        s.append(ch)
print('Yes' if a & 1 else 'No')