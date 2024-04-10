import os
### START FAST IO ###
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
  def wrappedfunc(*args, **kwargs):
    if stack:
      return f(*args, **kwargs)
    else:
      to = f(*args, **kwargs)
      while True:
        if type(to) is GeneratorType:
          stack.append(to)
          to = next(to)
        else:
          stack.pop()
          if not stack:
            break
          to = stack[-1].send(to)
      return to
  return wrappedfunc
#### END ITERATE RECURSION ####


T = read_i()
while T:
  T -= 1

  n = read_i()
  m = read_i()
  sz = [read_i() for i in range(n)]
  val = [read_i() for i in range(n)]
  adj = [[] for i in range(n)]
  for i in range(n-1):
    a = read_i() - 1
    b = read_i() - 1
    adj[a].append(b)
    adj[b].append(a)

  @iterative
  def dfs(u, p):
    orig = sz[u]
    bcnt = 0
    for v in adj[u]:
      if v == p:
        continue
      ok, bad = yield dfs(v, u)
      if not ok:
        yield False, 0
      sz[u] += sz[v]
      bcnt += bad

    cbad = sz[u] - val[u]
    if cbad % 2 or cbad < 0 or cbad//2 > sz[u] or cbad//2 > bcnt + orig:
      yield False, 0

    yield True, cbad // 2

  if dfs(0, 0)[0]:
    write_s("YES")
  else:
    write_s("NO")


print_ans()