t = int(input())
for i in range(t):
    n = int(input())
    a = input()
    first, last = 0, 0
    for i in range(n):
        if a[i] == '1':
            first = i
            break;
    for i in range(n - 1, -1, -1):
        if a[i] == '1':
            last = i
            break
    if (a[last] == '0'):
        print(n)
    else:
        mx = min(first, n - 1 - last)
        print(2 * (n - mx))