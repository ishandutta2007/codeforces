S=raw_input()
T=[]
for i in S:
    T.append(min(int(i), 9-int(i)))
if T[0]==0: T[0]=9
print "".join(map(str, T))