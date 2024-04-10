n,m=map(int,input().split())
l=[(lambda x:[i+1,[x[j]if j%2==0 else chr(155-ord(x[j]))for j in range(m)]])(input())for i in range(n)]
print(*[i[0]for i in sorted(l,key=lambda x:x[1])])