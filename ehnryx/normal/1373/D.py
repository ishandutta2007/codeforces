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


T = read_i()
while T:
  T -= 1

  n = read_i()
  a = [read_i() for i in range(n)]
  init = sum(a[::2])

  odd, even = 0, 0
  min_odd, min_even = 0, 0
  ans = init
  for i, v in enumerate(a):
    if i % 2:
      odd += v
      cur = odd - even
      ans = max(ans, init + cur - min_odd)
      min_odd = min(min_odd, cur)
    else:
      even += v
      cur = odd - even + a[0]
      ans = max(ans, init + cur - min_even)
      min_even = min(min_even, cur)
  write_i(ans)


print_ans()