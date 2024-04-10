for _ in range(int(input())):
    a,b,n,s=map(int,input().split())
    print("YNEOS"[min(s//n,a)*n+b<s::2])