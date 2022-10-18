a,b,c,d=map(int,input().split())
if (a+b>c and b+c>a and c+a>b) or (a+b>d and b+d>a and d+a>b) or (a+d>c and d+c>a and c+a>d) or (d+b>c and b+c>d and c+d>b):
 print("TRIANGLE")
elif a+b==c or a+b==d or a+c==b or a+c==d or a+d==b or a+d==c or b+c==a or b+c==d or b+d==a or b+d==c or c+d==a or c+d==b:
 print("SEGMENT")
else:
 print("IMPOSSIBLE")