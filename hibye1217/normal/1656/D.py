import sys; input = sys.stdin.readline; print = sys.stdout.write;

def f(x): return x*(x+1) // 2
def ex(x):
    res = 1
    for _ in range(x): res *= 2
    return res

for _ in range( int( input() ) ):
    n = int( input() )
    m, cnt = n, 0
    while m > 1:
        if m % 2 == 1: break
        m //= 2; cnt += 1
    if m == 1:
        print("-1\n"); continue
    y, x = m//2 - 1, cnt
    if n >= f( ex(x+1) ): print( str( ex(x+1) ) + '\n' )
    else: print(str(m) + '\n')