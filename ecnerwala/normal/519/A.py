a = ''.join(input() for _ in range(8))
x = lambda b: b.count('P') + 3 * b.count('N') + 3 * b.count('B') + 5 * b.count('R') + 9 * b.count('Q')
w = x(a)
b = x(a.upper()) - w
print('Draw' if w == b else 'White' if w > b else 'Black')