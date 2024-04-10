k,n,w=map(int,input().split())
print(max(k*sum(range(w+1))-n,0))