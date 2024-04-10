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
  n = read_i()
  a = [read_i() for i in range(n)]
  a = [0] + sorted(a)
  write_i(max([x - y for x, y in zip(a[1:], a)]))
  T -= 1


print_ans()