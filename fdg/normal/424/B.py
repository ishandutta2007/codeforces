import sys, re

#f = open('..\\input.txt','r')
f = sys.stdin

lines = [line.strip() for line in f.readlines()]

data = map(int, lines[0].split())
n, s = data[0], data[1]

x, y, k, d = [], [], [], []

for i in xrange(n):
  data = map(int, lines[i + 1].split())
  x.append(data[0])
  y.append(data[1])
  k.append(data[2])
  d.append(data[0] * data[0] + data[1] * data[1])

l, r = 0.0, 1000000000.0

for it in xrange(200):
  m = (l + r) / 2
  cur = s
  for i in xrange(n):
    if d[i] < m * m:
      cur = cur + k[i]
  if cur >= 1000000:
    r = m
  else:
    l = m

if r > 999999999:
  r = -1

print r