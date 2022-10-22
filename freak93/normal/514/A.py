X = input()

A = ""
first = True
for ch in X:
    if ch == '9' and first:
        A += ch
    else:
        v = ord(ch) - ord('0')
        if v > 4:
            v = 9 - v
        A += chr(v + ord('0'))

    first = False
print(A)