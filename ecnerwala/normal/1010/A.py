i=input
i()
m=int(i())
v=m
try:
 for a in map(int, (i()+' '+i()).split()):v*=a/(a-1)
except:v=m-1
print(v-m)