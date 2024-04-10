line = raw_input()
r = str(eval(line))
cur = 0
ans = ''
for c in r:
    x = ord(c)
    while cur < x:
        cur += 1
        ans += '+'
    while cur > x:
        cur -= 1
        ans += '-'
    ans += '.'
print ans