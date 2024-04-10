
d={}
D={}

def add(di,st):
  if(st[0] not in di.keys()): di[st[0]]={}
  if(len(st)>1): add(di[st[0]],st[1:])

def dfs(x):
  su=0
  for i in x.keys():
    su+=1+dfs(x[i])
  return su

while True:
  try: s=raw_input()
  except EOFError: break
  s=s.split(":\\")
  if(s[0] not in d.keys()):
    d[s[0]]={}
    D[s[0]]={}
  first=s[1].split("\\")[0]
  if(first not in D[s[0]]): D[s[0]][first]=0
  D[s[0]][first]+=1
  add(d[s[0]],s[1].split("\\")[:-1])
  
b=0
for i in D.keys():
  for j in D[i].keys(): b=max(b,D[i][j])

a=0
for i in D.keys():
  for j in D[i].keys():
    a=max(a,dfs(d[i][j]))

print str(a)+" "+str(b)