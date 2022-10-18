N=int(raw_input())
text=raw_input().strip()
text2=text.split(".")
text=[]
for i in text2: text+=i.split("?");
text2=[]
for i in text: text2+=i.split("!");
text=[]
for i in text2: text+=[i.strip()];

while text[-1]=="": text=text[:-1]

ret=0
s=0
for i in range(len(text)):
  if(s==0):
    if(s+len(text[i])+1>N):
      ret=-1
      break
    else:
      ret+=1
      s=len(text[i])+1
  else:
    if(s+len(text[i])+2>N):
      if(len(text[i])+1>N):
        ret=-1
        break
      else:
        ret+=1
        s=len(text[i])+1
    else:
      s+=len(text[i])+2


if(ret==-1): print "Impossible"
else: print ret