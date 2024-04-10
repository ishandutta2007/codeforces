n = int(input())
b = list(map(int, input().split()))
a = [0] * n
a[-1] = b[-1]
s = b[-1]
for i in reversed(range(n - 1)):
    a[i] = b[i] + s
    s = -s + a[i]
print(' '.join(map(str, a)))