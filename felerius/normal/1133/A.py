h1, m1 = map(int, input().split(':'))
h2, m2 = map(int, input().split(':'))

t1 = h1 * 60 + m1
t2 = h2 * 60 + m2
mid = (t1 + t2) // 2
print(f'{mid // 60:02}:{mid % 60:02}')