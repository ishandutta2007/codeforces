n=int(input())
a=sorted(map(int,input().split()))
print(min((a[n-1]-a[0])*(a[-1]-a[n]),(a[-1]-a[0])*min(a[n-1+i]-a[i] for i in range(n))))