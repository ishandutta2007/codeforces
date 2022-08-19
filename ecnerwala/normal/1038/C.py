i=lambda:[*map(int,input().split())]
i()
a=i()
b=i()
print(sum(a)-sum(sorted(a+b)[::2]))