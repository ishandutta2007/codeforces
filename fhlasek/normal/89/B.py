
N=int(raw_input())

class Widget:
  def __init__(self,x,y,name):
    self.x=x
    self.y=y
    self.name=name
  def get(self):
    return (self.x,self.y)

class Box:
  def __init__(self,name):
    self.name=name
    self.border=0
    self.spacing=0
    self.inside=[]
    self.x=-1
    self.y=-1
  def add(self,x):
    self.inside.append(x)

class VBox(Box):
  def get(self):
    if self.x!=-1: return (self.x,self.y)
    if(len(self.inside)==0): return (0,0)
    x=self.inside[0].get()[0]
    y=0
    for i in self.inside:
      s=i.get()
      x=max(x,s[0])
      y+=s[1]
    self.x=x+2*self.border
    self.y=y+(len(self.inside)-1)*self.spacing+2*self.border
    return (self.x,self.y)


class HBox(Box):
  def get(self):
    if self.x!=-1: return (self.x,self.y)
    if(len(self.inside)==0): return (0,0)
    y=self.inside[0].get()[1]
    x=0
    for i in self.inside:
      s=i.get()
      y=max(y,s[1])
      x+=s[0]
    self.x,self.y=(x+(len(self.inside)-1)*self.spacing+2*self.border,y+2*self.border)
    return self.x,self.y


w={}

for i in range(N):
  l=raw_input();
  if len(l.split())>1:
    l=l.split()
    t=l[0]
    r=l[1]
    if(t=="Widget"):
      n=r.split("(")[0]
      p=r.split("(")[1].rstrip().rstrip(")")
      w[n]=Widget(int(p.split(",")[0]),int(p.split(",")[1],),n)
    if(t=="VBox"): w[r]=VBox(r)
    if(t=="HBox"): w[r]=HBox(r)
  else:
    l=l.split(".")
    n=l[0]
    r=l[1].rstrip().rstrip(")").split("(")
    if(r[0]=="pack"): w[n].add(w[r[1]])
    if(r[0]=="set_border"): w[n].border=int(r[1])
    if(r[0]=="set_spacing"): w[n].spacing=int(r[1])

for i in sorted(w.keys()):
  s=w[i].get()
  print i,s[0],s[1]