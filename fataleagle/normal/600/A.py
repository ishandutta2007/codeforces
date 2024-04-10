S = raw_input()
A = S.split(';')
B = []
for i in A:
    B.extend(i.split(','))
num = []
word = []
for i in B:
    if not i:
        word.append(i)
    elif i == '0':
        num.append(i)
    elif i[0] == '0' or not i.isdigit():
        word.append(i)
    else:
        try:
            a = int(i)
        except:
            word.append(i)
        else:
            num.append(i)

if not num:
    print '-'
else:
    print '"' + ','.join(num) + '"'

if not word:
    print '-'
else:
    print '"' + ','.join(word) + '"'