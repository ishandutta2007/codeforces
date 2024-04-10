n = int(input())

if (n <= 4):
  print(int(n * (n - 1) / 2))
else:
  v = 9
  dig = 10
  x = n * 2 - 1
  while (v + dig * 9 <= x):
    v += dig * 9
    dig *= 10
  
  ans = 0
  f = True
  while (f):
    f = False

    y = v // 2
    pairs = y - max(0, v - n - 1)

    if (pairs > 0):
      f = True
      ans += pairs
    
    v += dig
    if (n * 2 - 1 < v):
      break
  
  print(ans)