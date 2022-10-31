n=int(input())
a=sorted(list(map(int, input().split())))
print(min(a[n-2]-a[0], a[n-1]-a[1]))