n=int(input())
m=int(input())
a=[int(input()) for _ in range(n)]
print(max((sum(a)+m+n-1)//n, max(a)),max(a)+m)