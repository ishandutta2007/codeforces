a=sorted(map(int,input().split()))
s=sum(a)
print("YNEOS"[s%2 or s//2 not in [sum(a[:3]),sum(a[1:3])]::2])