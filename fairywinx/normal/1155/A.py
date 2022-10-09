n = int(input())
a = input()
mx = a[0]
mx_i = 1
for i in range(n):
    if a[i] < mx:
        print('YES')
        print(mx_i, i + 1)
        exit(0)
    else:
        mx_i = i + 1
        mx = a[i]
print('NO')