l = [int(input()) for i in range(11)]

for i in range(11):
    x = l.pop()
    a = abs(x)**0.5
    b = x**3 * 5
    r = a + b
    if r > 400:
        print('f({}) = MAGNA NIMIS!'.format(x))
    else:
        print('f({}) = {:.2f}'.format(x, r))