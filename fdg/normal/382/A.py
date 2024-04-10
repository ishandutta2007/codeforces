import sys, re

# f = open('input.txt','r')
f = sys.stdin

lines = [line.strip() for line in f.readlines()]

init = lines[0]
left = lines[1]

l = init.find('|')
r = len(init) - l - 1

need = abs(l - r)
if need > len(left):
  print 'Impossible'
else:
  split = left[need:]
  left = left[0:need]
  if len(split) % 2 != 0:
    print 'Impossible'
  else:
    splitl, splitr = split[0:len(split) / 2], split[len(split) / 2:]
    if l < r:
      print splitl + left + init + splitr
    else:
      print splitl + init + left + splitr