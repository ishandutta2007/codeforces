__author__ = 'Fdg'
a,b,n=map(int,raw_input().split())

def gcd(a,b):
    if not b: return a
    else: return gcd(b,a%b)

while 1:
    g=gcd(a,n)
    if n<g:
        print(1)
        break
    else: n-=g
    g=gcd(b,n)
    if n<g:
        print(0)
        break
    else:
        n-=g