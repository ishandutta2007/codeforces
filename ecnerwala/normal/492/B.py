n,l = map(int, input().split())
a = map(int, input().split())
a = sorted(a)
print( max(a[0],l -a[-1], max((abs(i-j)/2 for i,j in zip(a,a[1:])),default=0)))