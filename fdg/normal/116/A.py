__author__ = 'Fdg'
n=int(input())

ans,cur = 0,0

for i in range(n):
    a,b=map(int,raw_input().split())
    cur-=a
    cur+=b
    ans=max(ans,cur)
print(ans)