N = input()
mail = [x for x in raw_input().replace(' ', '').split('0') if x]

if mail:
    print sum(len(x) for x in mail) + len(mail) - 1
else:
    print 0