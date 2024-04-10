from math import factorial

n = int(raw_input())
print sum([factorial(n) // factorial(k) // factorial(n - k) for k in [5, 6, 7]])