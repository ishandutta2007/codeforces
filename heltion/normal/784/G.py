n = str(eval(input()))
for x in n:
    print('>')
    for i in range(ord(x)):
        print('+', end = '')
    print('.')