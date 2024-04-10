a = list(map(int, input().split()))
a = sorted(a)
if a[0] + a[3] == a[1] + a[2]:
    print('YES')
elif a[3] == a[2] + a[1] + a[0]:
    print('YES')
else:
    print('NO')