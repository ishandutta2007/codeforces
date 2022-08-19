n=int(input())
a=[int(i)for i in input().split()]
print(' '.join(str(a.index(i+1)+1) for i in range(n)))