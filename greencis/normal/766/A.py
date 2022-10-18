i = input
a = i()
b = i()
if a == b:
    print(-1)
else:
    print(max(len(a), len(b)))