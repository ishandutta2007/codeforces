n = int(input()) + 1

a = [1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000]

for x in a:
  if x >= n:
    print(x)
    break
else:
  assert False