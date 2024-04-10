res = str(eval(input()))

for c in res:
    dif = int(c)
    for i in range(48 + dif):
        print('+')
    print('.>')