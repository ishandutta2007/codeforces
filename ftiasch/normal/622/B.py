h, m = map(int, input().split(':'))
a = int(input())
b = (h * 60 + m + a) % (24 * 60)
print(f'{b // 60:02d}:{b % 60:02d}')