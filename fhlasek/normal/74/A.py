N=int(raw_input())
a=()
for i in range(N):
  l=raw_input().split()
  b=(100*int(l[1])-50*int(l[2])+int(l[3])+int(l[4])+int(l[5])+int(l[6])+int(l[7]),l[0])
  a=max(a,b)

print a[1]