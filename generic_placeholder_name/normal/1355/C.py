A,B,C,D=map(int,input().split())
res = 0
for i in range(max(A+B, C), C+D+1):
    res+=(i-A-B+1+max(0, i-B-C-1)-max(0, i-A-C)-max(0, i-B-B))*(min(i-C, D-C+1))
print(int(res))