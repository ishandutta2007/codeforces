from re import S
import sys
input = sys.stdin.readline
print = sys.stdout.write

for _ in range( int( input() ) ):
    n, x = tuple( map( int, input().split() ) )
    arr = [0] + list( map( int, input().split() ) ); arr.sort()
    prf = [ 0 for _ in range(n+1) ]
    for i in range(1, n+1): prf[i] = prf[i-1] + arr[i]
    ans, ptr = 0, 0
    for i in range(n, 0, -1):
        st, ed = 0, 1000000010
        while st+1 <= ed-1:
            mid = (st+ed) // 2
            res = prf[i] + i*(ptr+mid-1)
            if res <= x: st = mid
            else: ed = mid
        ans += i*st; ptr += st
        #print(f"MID {i}: {ans}, {ptr}\n")
    print(str(ans)+'\n')