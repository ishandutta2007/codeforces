s = input()
s %= 256

cur = 0
ans = '+' * ord('0')
s = str(s)
for c in s:
    num = int(c)
    while cur < num:
        cur += 1
        ans += '+'
    while cur > num:
        cur -= 1
        ans += '-'
    ans += '.'
print ans