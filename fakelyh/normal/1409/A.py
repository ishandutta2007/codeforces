for _ in range(int(input())):
    a,b=map(int,input().split())
    if a>b:
        t=a
        a=b
        b=t
    k=(b-a)//10
    if k*10==b-a:
        print(k)
    else:
        print(k+1)