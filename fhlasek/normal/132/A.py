
a=raw_input().rstrip("\n")

def rev(x):
  res=0
  for i in range(8):
    res=2*res+x%2
    x/=2
  return res

for i in range(len(a)):
  if(i): prev=rev(ord(a[i-1]))
  else: prev=0
  akt=rev(ord(a[i]))
  res=(prev-akt+256)%256
  print res