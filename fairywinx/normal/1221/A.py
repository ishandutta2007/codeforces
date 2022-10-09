a = int(input())
b = []
ans = 0
for i in range(a):
    n = int(input())
    b = list(map(int, input().split()))
    b = sorted(b)[::-1]
    while(True):
        #print(b)
        if b[-1] == 2048:
            ans = 1
        if len(b) == 1:
            break
        if b[-1] > 2048:
            break
        if b[-1] != b[-1 - 1]:
            b.pop()
        elif b[-1] == b[-1 - 1]:
            b.pop()
            b[-1] = 2 * b[-1]
        b = sorted(b)[::-1]
    if ans == 1:
        print('YES')
    else:
        print('NO')
    ans = 0