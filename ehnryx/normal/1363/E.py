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
        continue
      stack.pop()
      if not stack: break
      to = stack[-1].send(to)
    return to
  return wrapped_func
#### END ITERATE RECURSION ####


n = read_i()
cost = [0 for i in range(n + 1)]
val = [0 for i in range(n + 1)]
for i in range(1, n+1):
  cost[i] = read_i()
  a = read_i()
  b = read_i()
  val[i] = 0 if a == b else 1 if a else -1

adj = [[] for i in range(n+1)]
for i in range(1, n):
  a = read_i()
  b = read_i()
  adj[a].append(b)
  adj[b].append(a)

@iterative
def solve(u, p, best):
  best = min(best, cost[u])
  a = (val[u] == 1)
  b = (val[u] == -1)
  res = 0
  for v in adj[u]:
    if v != p:
      t, c, cur = yield solve(v, u, best)
      res += cur
      if t == 1:
        a += c
      else:
        b += c
  rem = min(a, b)
  res += 2 * rem * best
  yield 1 if a > b else -1, max(a, b) - rem, res

result = solve(1, 0, 0x3f3f3f3f)
write_i(result[-1] if result[-2] == 0 else -1)


print_ans()