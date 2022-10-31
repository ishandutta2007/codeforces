R=lambda:list(map(int,input().split()))
n,s=R()
a=R()
print('YES'if sum(a)-max(a)<=s else'NO')