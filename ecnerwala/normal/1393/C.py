from collections import*
C=Counter
for s in[*open(0)][2::2]:x=s.split();c=C(C(x).values());v=max(c);print((len(x)-c[v])//(v-1)-1)