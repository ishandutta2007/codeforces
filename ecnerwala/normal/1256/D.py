for _ in range(int(input())):
    n,k=map(int,input().split())
    o=['1']*n
    for i,v in enumerate(i for i,c in enumerate(input()) if c=='0'):
        d=min(v-i,k)
        k-=d
        o[v-d]='0'
    print(''.join(o))