from collections import *
f=lambda s:(Counter(s),len(set(s))==len(s)and sum(s[i]>s[j] for i in range(len(s))for j in range(i,len(s)))&1)
for _ in range(int(input())):
    n,s,t=input(),input(),input()
    print("YNEOS"[f(s)!=f(t)::2])