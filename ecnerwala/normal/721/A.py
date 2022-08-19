a=[0];i=input;i();s=i()
for c in s:
 if c>'B':a+=[0]
 else:a[-1]+=1
a=list(filter(None,a))
print(len(a),*a)