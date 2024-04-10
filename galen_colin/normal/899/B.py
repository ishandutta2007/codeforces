n = int(input())

a = [int(i) for i in input().split()]

f = 0
mon = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for i in range(12):
  ff = 1
  leap = False
  for j in range(n):
    ind = (i + j) % 12
    if (a[j] != mon[ind]):
      if (not leap and mon[ind] == 28 and a[j] == 29):
        leap = True
      else:
        ff = 0
  
  if ff:
    f = 1

if f:
  print("YES")
else:
  print("NO")