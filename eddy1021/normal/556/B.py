n, a=int(input()), list(map(int,input().split()))
dlt=[(n-a[0])%n, (a[0]-n)%n]
for i in range(n):
  if (a[i] + dlt[i%2]) % n != i:
    print( "No" )
    exit(0)
print("Yes")