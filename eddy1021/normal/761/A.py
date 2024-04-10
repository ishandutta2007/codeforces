a,b=list(map(int,input().split()))
print("YES"if abs(a-b)<=1 and a+b>0 else"NO")