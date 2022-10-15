n,m,a = map(int, input().split())
total = ((n+a-1) // a) * ((m+a-1) // a)
print(total)