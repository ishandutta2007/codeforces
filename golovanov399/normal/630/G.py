from math import factorial

def C(n, k):
    return factorial(n) // factorial(k) // factorial(n - k)

n = int(raw_input())
print C(n + 4, 5) * C(n + 2, 3)