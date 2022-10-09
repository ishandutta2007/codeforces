a, b = map(int, input().split())
if a == b:
    print(str(a) + '0', str(b) + '1')
elif a == 9 and b == 1:
    print(9, 10)
elif a == b - 1:
    print(str(a), str(b))
else:
    print(-1)