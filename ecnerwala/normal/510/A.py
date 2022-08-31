n,m=map(int,input().split())
a,b='.'*(m-1),'#'
for i in range(n):print((a+'#'if i%4<2 else'#'+a)if i%2 else'#'*m)