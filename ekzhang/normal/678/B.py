def offset(yr):
    if yr % 400 == 0:
        return 2
    if yr % 100 == 0:
        return 1
    if yr % 4 == 0:
        return 2
    return 1

y = input()
x = 0
o = offset(y)
while True:
    y += 1
    x += offset(y)
    if x % 7 == 0 and offset(y) == o:
        break

print y