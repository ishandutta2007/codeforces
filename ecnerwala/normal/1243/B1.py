i=input
for _ in range(int(i())):
 i()
 d=[(x,y)for x,y in zip(i(),i()) if x!=y]
 print("YNEOS"[d!=[d[0]]*2::2])