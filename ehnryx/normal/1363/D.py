from sys import stdin, stdout

def query(arr):
  stdout.write("? " + str(len(arr)) + " " + " ".join([str(x) for x in arr]) + "\n")
  stdout.flush()
  return int(stdin.readline())

def solve_case():
  n, k = [int(x) for x in stdin.readline().split()]
  sub = []
  have = set()
  for i in range(k):
    sub.append([int(x) for x in stdin.readline().split()][1:])
    for v in sub[-1]:
      have.add(v)

  extra = 0
  for i in range(1, n+1):
    sub.append([])
    if i not in have:
      sub[-1].append(i)
    if not sub[-1]:
      sub.pop()
    else:
      k += 1
      extra = 1

  def get(l, r):
    arr = []
    for i in range(l, min(k, r)):
      arr += sub[i]
    return arr

  l = 0
  r = 2**10
  big = query(get(l, r))
  while l+1 < r:
    m = (l + r) // 2
    left = query(get(l, m))
    if left == big:
      r = m
    else:
      l = m

  ans = [big for i in range(k)]
  ans[l] = query(get(0, l) + get(l+1, k))
  if extra:
    ans = ans[:-1]
  stdout.write("! " + " ".join([str(x) for x in ans]) + "\n")
  stdout.flush()
  stdin.readline()  # read "Correct"


T = int(stdin.readline())
while T:
  T -= 1
  solve_case()