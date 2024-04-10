a, u = map(int, input().split())
b, v = map(int, input().split())
h, t = map(int, input().split(':'))
t += (h - 5) * 60
print(min(t + u - 1, 1139) // b - max(t - v, -1) // b)