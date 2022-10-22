n, k = map(int, input().split())

a = [-10 ** 9] + list(map(int, input().split())) + [10 ** 9]
if k > 1:
    print('Yes')
else:
    i = a.index(0)
    b = int(input())
    
    f = True
    for j in range(1, n):
        if a[j] <= a[j - 1] and a[j] != 0:
            f = False
            
    if f and a[i - 1] < b and a[i + 1] > b:
        print('No')
    else:
        print('Yes')