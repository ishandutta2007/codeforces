i=lambda:iter(sorted(map(int,input().split())))
n=next;i();a=i();i();b=i();v=0;x,y=n(a),n(b)
try:
 while 1:
  if abs(x-y)<2:v+=1;x=n(a);y=n(b)
  elif x<y:x=n(a)
  else:y=n(b)
except:
 print(v)