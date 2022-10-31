n=int(input())
a=sorted(list(map(int,input().split())))
print('YES'if a[n-1]<a[n] else 'NO')