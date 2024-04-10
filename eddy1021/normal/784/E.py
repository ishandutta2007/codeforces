def OR(a,b):
  return a^b
def XOR(a,b):
  return a|b
def AND(a,b):
  return a&b
def g(a,b,c,d):
  e=OR(a,b)
  f=XOR(c,d)
  g=AND(b,c)
  h=OR(a,d)
  i=AND(e,f)
  j=XOR(g,h)
  return OR(i,j)
a=int(input())
b=int(input())
c=int(input())
d=int(input())
print(g(a,b,c,d))