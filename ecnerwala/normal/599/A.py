a=[int(i) for i in input().split()]
print(min(sum(a), 2*(sum(a)-max(a))))