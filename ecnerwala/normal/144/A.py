n,a=int(input()),sorted((-int(v),i) for i,v in enumerate(input().split()))
print(a[0][1]+n-1-a[-1][1]-(a[0][1] > a[-1][1]))