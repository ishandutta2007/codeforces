n = int(input())
a = list(map(int, input().split(' ')))
ar = list(reversed(a))
if a[-1] == 0:
    try:
        print(n - ar.index(1))
    except ValueError:
        print(n)
else:
    try:
        print(n - ar.index(0))
    except ValueError:
        print(n)