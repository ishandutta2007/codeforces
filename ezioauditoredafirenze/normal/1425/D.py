import sys
input = sys.stdin.readline
from sys import stdin, stdout
from collections import defaultdict, Counter
from functools import lru_cache
M = 10**9+7

fact = [1]*(2001)
def fac(n):
    if(n==0 or n==1):
        return 1
    elif fact[n]!=1:
        return fact[n]
    fact[n] = (fac(n-1)*(n%M))%M
    return fact[n]

ncr = [[0 for i in range(2001)] for j in range(2001)]
def choose(n,k):
    if n<k:
        return 0
    if k==0 or k==n:
        return 1
    elif k==1 or k==n-1:
        return n%M
    elif ncr[n][k]!=0:
        return ncr[n][k]
    else:
        ncr[n][k] = ( fac(n) * ( pow(fac(k),M-2,M) * pow(fac(n-k),M-2,M))%M )%M
        return ncr[n][k]

def find_inter(x1, y1, x2, y2, x3, y3, x4, y4):  
    x5 = max(x1, x3) 
    y5 = max(y1, y3) 
    x6 = min(x2, x4) 
    y6 = min(y2, y4)  
    if (x5 > x6 or y5 > y6) : 
        return [0]
    return [1, x5, y5, x6, y6]

def main():
    n,m,r = [int(s) for s in input().split()]
    snakes = [[int(s) for s in input().split()] for i in range(n)]
    X = max([i[0] for i in snakes])
    Y = max([i[1] for i in snakes])
    num = [1]*n
    for i in range(n-1):
        for j in range(i+1,n):
            if max(abs(snakes[i][0]-snakes[j][0]),abs(snakes[i][1]-snakes[j][1])) <= r:
                num[i]+=1
                num[j]+=1
    
    ans = 0
    ncm = choose(n,m)
    for i in range(n):
        v = (((ncm - choose(n-num[i],m))%M)*((snakes[i][2]**2)%M))%M
        ans = (ans + v)%M
    
    pre = [[0 for i in range(Y+r+1)] for j in range(X+r+1)]
    for i in range(n):
        pre[snakes[i][0]][snakes[i][1]] = 1
    for i in range(1,X+r+1):
        pre[i][0] += pre[i-1][0]
    for i in range(1,Y+r+1):
        pre[0][i] += pre[0][i-1]
    for i in range(1,X+r+1):
        for j in range(1,Y+r+1):
            pre[i][j] += pre[i][j-1] + pre[i-1][j]-pre[i-1][j-1]

    num1 = [[0 for i in range(n)]for j in range(n)]
    for i in range(n-1):
        for j in range(i+1,n):
            x1,y1,x2,y2 = snakes[i][0], snakes[i][1], snakes[j][0],snakes[j][1]
            inter = find_inter(max(x1-r,0),max(y1-r,0),x1+r,y1+r,max(x2-r,0),max(y2-r,0),x2+r,y2+r)
            if inter[0]==1:
                blx,bly,trx,ty = inter[1:]
                # print(inter[1:])
                num1[i][j] = pre[trx][ty]
                if blx-1>=0 and bly-1>=0:
                    num1[i][j] += pre[blx-1][bly-1] 
                if blx-1>=0:
                    num1[i][j] -= pre[blx-1][ty] 
                if bly-1>=0:
                    num1[i][j] -= pre[trx][bly-1]
    ans1 = 0  
    for i in range(n-1):
        for j in range(i+1,n):
            x = num[i]
            y = num[j]
            z = num1[i][j]
            v = ( (( ncm + ( choose(n-x-y+z,m) - (choose(n-x,m) + choose(n-y,m))%M )%M )%M) * ((snakes[i][2]*snakes[j][2])%M) )%M
            ans1 = (ans1 + v)%M
    print((ans+(2*ans1)%M)%M)

if __name__== '__main__':
    main()