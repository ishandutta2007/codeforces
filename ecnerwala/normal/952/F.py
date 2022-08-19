res = 0
val = 0
sub = False
for c in input()+'+':
  if c == '+' or c == '-':
     if sub: val *= -1
     res += val
     val = 0
     sub = (c == '-')
  val *= 10
  val += ord(c) - ord('0')
print(res)