def p(k):
  a, i = 8, 1
  while k > 0:
    if k % 2 == 1: i = (i * a) % 10
    a, k= (a * a) % 10, k >> 1
  return i
print( p( int(input()) ) )