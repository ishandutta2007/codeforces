def getAns(n, k, x, y):
    if n % 3 != 0:
        return 'no'
    
    if y < x:
        x, y = y, x # now y > x

    smallest = float('inf')
    temp = None
    for i in [-1, 1]:
        for j in [-1, 1]:
            if i == -1 and j == -1:
                if 2*y - x <= k and (((2*y - x) % 3) == (k % 3)):
                    temp = x + y
            elif i == -1 and j == 1:
                if 2*x + y <= k and (((2*x + y) % 3) == (k % 3)):
                    temp = 2*y + x
            elif i == 1 and j == -1:
                if 2*y + x <= k and (((2*y + x) % 3) == (k % 3)):
                    temp = 2*x + y
            else:
                if x + y <= k and (((x + y) % 3) == (k % 3)):
                    temp = 2*y - x
            if temp != None and temp < smallest:
                smallest = temp
    
    if n - k >= smallest:
        return 'yes'
    return 'no'

T = input()
for _ in xrange(T):
    N, K, D1, D2 = map(int, raw_input().split())
    print getAns(N, K, D1, D2)