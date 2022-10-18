__author__ = 'Fdg'

reader=lambda:map(int,raw_input().split())
n,x,y=reader()
l,r=-1,1000000000
while r-l>1:
    m=(l+r)//2
    if 100*(x+m)>=y*n: r=m
    else: l=m
print(r)