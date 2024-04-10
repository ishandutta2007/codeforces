### START FAST IO ###
import os
os_input = os.read(0, int(1e7)).split()
os_input_pos = -1
answer_list = []
def read_s():
  global os_input_pos
  os_input_pos += 1
  return os_input[os_input_pos].decode()
def read_i():
  return int(read_s())
def write_s(v):
  answer_list.append(v)
def write_i(v):
  write_s(str(v))
def print_ans():
  os.write(1, "\n".join(answer_list).encode())
  os.write(1, "\n".encode())
#### END FAST IO ####

### START ITERATE RECURSION ###
from types import GeneratorType
def iterative(f, stack=[]):
  def wrapped_func(*args, **kwargs):
    if stack: return f(*args, **kwargs)
    to = f(*args, **kwargs)
    while True:
      if type(to) is GeneratorType:
        stack.append(to)
        to = next(to)
      else:
        stack.pop()
        if not stack: break
        to = stack[-1].send(to)
    return to
  return wrapped_func
#### END ITERATE RECURSION ####


INF = int(1e19)

T = 1
while T:
  T -= 1

  n = read_i()
  m = read_i()
  x, k, y = [read_i() for i in range(3)]

  a = [read_i() for i in range(n)]
  b = [read_i() for i in range(m)]
  goal = set(b)
  result = []
  groups = []
  ends = []
  start = 0
  for i in range(n):
    if a[i] in goal:
      result.append(a[i])
      if i > start:
        groups.append(a[start:i])
        ends.append(max(a[start-1] if start > 0 else 0, a[i]))
      start = i + 1
  if start < n:
    groups.append(a[start:])
    ends.append(max(a[start-1] if start > 0 else 0, 0))

  if result != b:
    write_i(-1)
    continue

  ans = 0
  for i, g in enumerate(groups):
    cur = INF
    length = len(g)
    if max(g) < ends[i]:
      cur = min(cur, length * y)
    if length >= k:
      cur = min(cur, (length % k) * y + (length // k) * x)
      cur = min(cur, (length - k) * y + x)
    if cur == INF:
      write_i(-1)
      break
    ans += cur
  else:
    write_i(ans)


print_ans()