import sys
from math import *
def main():
    
    n = int(sys.stdin.readline().strip())
    N = n
    #n, x = map(int, sys.stdin.readline().split())
    #q = sorted(list(map(int, sys.stdin.readline().split())))
    fl = [0, 0] + [1 for i in range(n - 1)]
    p = []
    d = dict()
    for i in range(2, n + 1):
        if fl[i]:
            p.append(i)
            for o in range(i * i, n + 1, i):
                fl[o] = 0
                
                
    l = len(p)
    for i in p:
        d[i] = n // i
    res = 1
    nach = 65
    otrlen = 100
    for i in p:
        d[i] = n // i   
    for i in range(96):
        s = 0
        for o in range(otrlen):
            ind = nach + o + otrlen * i
            if ind < l:
                print("B", p[ind], flush=True)
                ans = int(sys.stdin.readline().strip()) 
                s += d[p[ind]]
            else:
                break
        print("A", 1, flush=True)
        lenn = int(sys.stdin.readline().strip()) 
        n -= s
        if n != lenn:
            for o in range(otrlen):
                ind = nach + o + otrlen * i
                if ind < l:
                    print("B", p[ind], flush=True)
                    ans = int(sys.stdin.readline().strip()) 
                    if ans == 1:
                        res *= p[ind]
                        break
                else:
                    break
            break  
    for i in p[:nach][::-1]:
        print("B", i, flush=True)
        ans = int(sys.stdin.readline().strip())
        print("B", i, flush=True)
        ans = int(sys.stdin.readline().strip())
        if ans == 1:
            r = floor(log(N, i)) + 1
            l = 1
            while r > l + 1:
                m = l + r
                m //= 2
                print("B", i ** m, flush=True)
                ans = int(sys.stdin.readline().strip())
                if ans:
                    l = m
                else:
                    r = m
            res *= i ** l
    print("C", res, flush=True)
    return 0
        
        
                    
         
        
            
    
        
        
    
for test in range(1):
    main()