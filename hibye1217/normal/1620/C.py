import sys
input = sys.stdin.readline

for _ in range( int(input()) ):
    n, k, x = tuple( map( int, input().split() ) ); x -= 1
    s = input()
    arr, cnt = [], 0
    for i in range(n):
        if s[i] == '*':
            cnt += 1
        else:
            if cnt != 0: arr.append(cnt*k)
            cnt = 0
    if cnt != 0: arr.append(cnt*k)
    l = len(arr)
    suf = [ 1 for __ in range(l+1) ]
    for i in range(l-1, -1, -1):
        suf[i] = suf[i+1] * (arr[i]+1)
    ans = [ 0 for __ in range(l+1) ]
    for i in range(l):
        val = suf[i+1]
        ans[i] = (x // val)
        #print("AX", x, val, ans[i])
        x -= ans[i]*val
    lst, ptr = 'a', 0
    for c in s:
        if c == '*':
            if lst == '*': continue
            print('b'*ans[ptr], end=''); ptr += 1
        elif c == 'a': print('a', end='')
        lst = c
    print()