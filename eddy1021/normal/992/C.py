x,k=list(map(int,input().split()))
md=1000000007
print((pow(2,k+1,md)*x-pow(2,k,md)+1)%md if x>0 else 0)