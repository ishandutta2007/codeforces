m,s=map(int,input().split())
def g(s):
  a=''
  for i in range(m):v=min(9,s);a+=str(v);s-=v
  return a
a=g(s)
if s<1:print(-(m>1),-(m>1))
elif 9*m<s:print(-1,-1)
else:print(a[::-1]if a[-1]>'0'else'1'+g(s-1)[-2::-1],a)