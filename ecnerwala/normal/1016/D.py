i=lambda:[*map(int,input().split())]
n,m=i()
a,b=i(),i()
def s(a):
 r=0
 for i in a: r^=i
 return r
if s(a)==s(b):
 print("YES")
 b[0]^=s(a[1:])
 print(*b)
 for i in a[1:]:print(str(i)+' 0'*(m-1))
else:
 print("NO")