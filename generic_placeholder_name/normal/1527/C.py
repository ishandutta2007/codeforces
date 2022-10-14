for s in[*open(0)][2::2]:
    l=[*map(int,s.split())];a=0;n=len(l);p={x:0 for x in l}
    for i in range(n):a+=p[l[i]]*(n-i);p[l[i]]+=i+1
    print(a)