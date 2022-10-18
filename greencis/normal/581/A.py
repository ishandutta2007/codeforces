a, b = map(int, input().split())
x = min(a, b)
a -= x
b -= x
y = a // 2 + b // 2
print(str(x) + " " + str(y))