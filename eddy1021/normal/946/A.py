input()
a=list(map(int,input().split()))
print(sum(x for x in a if x > 0)-sum([x for x in a if x<0]))