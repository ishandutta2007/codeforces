N = int(raw_input())

path = []

import sys

def print_path():
  sys.stdout.write("/")
  for i in path: sys.stdout.write("%s/"%i)
  sys.stdout.write("\n")

for i in range(N):
  line = raw_input().strip()
  if(line == "pwd"): print_path()
  else:
    line = line.split()[1]
    if(line[0] == '/'):
      path = []
      line = line.lstrip("/")
    line = line.split("/")
    for i in line:
      if(i == ""): continue
      if(i == ".."): del path[-1]
      else: path.append(i)