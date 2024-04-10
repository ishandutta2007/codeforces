import sys, re

#f = open('..\\input.txt','r')
f = sys.stdin

lines = [line.strip() for line in f.readlines()]

data = map(int, lines[0].split())
n = data[0]
str2 = str(lines[1])

c1, c2 = 0, 0
for i in xrange(len(str2)):
  if str2[i] == 'x':
    c1 = c1 + 1
  else:
    c2 = c2 + 1

print abs(c1 - c2) / 2

ret = ""

for i in xrange(len(str2)):
  if c1 > c2 and str2[i] == 'x':
    ret = ret + "X"
    c1 = c1 - 1
    c2 = c2 + 1
  elif c2 > c1 and str2[i] == 'X':
    ret = ret + "x"
    c1 = c1 + 1
    c2 = c2 - 1
  else:
    ret = ret + str2[i]

print ret