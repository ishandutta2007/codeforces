b, k = map(int, input().split())
a = [int(s) for s in input().split()]
n = 0
m = 1
for i, c in enumerate(reversed(a)):
    n = (n + c * m) % 2
    m = (m * b) % 2
print('even' if n % 2 == 0 else 'odd')