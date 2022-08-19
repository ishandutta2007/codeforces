for _ in range(int(input())):
    n=int(input())
    a=[*map(int,input().split())]
    b=[]
    while a:
        v,i=min((v,i) for i,v in enumerate(a))
        b+=[v]
        if i:
            b+=a[:i-1]
            a=a[i-1:i]+a[i+1:]
        else:
            a=a[1:]
    print(*b)