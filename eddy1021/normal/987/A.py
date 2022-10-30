a=['Power', 'Time', 'Space', 'Soul', 'Reality', 'Mind']
b=['Power', 'Time', 'Space', 'Soul', 'Reality', 'Mind']
c=['purple', 'green', 'blue', 'orange', 'red', 'yellow']
for i in range(int(input())):
  s=input()
  for j in range(6):
    if s==c[j]:
      a.remove(b[j])
print(len(a))
for i in a: print(i)