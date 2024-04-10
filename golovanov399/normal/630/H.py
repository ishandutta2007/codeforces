from math import factorial

def C(n, k):
    return factorial(n) // factorial(k) // factorial(n - k)

n = int(raw_input())
print C(n, 5) * C(n, 5) * 120