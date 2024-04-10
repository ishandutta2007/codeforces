for _ in range(int(input())):
    n,k=map(int,input().split());a=sorted(map(int,input().split()));b,x=k,n-k*2
    for i in range(x,x+k):
        b-=a[i]<a[i+k]
    print(b+sum(a[:x]))