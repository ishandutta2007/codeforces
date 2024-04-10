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

from collections import deque, defaultdict
from itertools import product, permutations, accumulate
from itertools import zip_longest, groupby, takewhile
from heapq import heappush, heappop, heapify, merge


T = read_i()
while T:
  T -= 1

  x, y = read_i(), read_i()
  if x >= 0 and y >= 0 and (x + y) % 2 == 0:
    if x % 2 == 0:
      write_s("{} {}".format(x//2, y//2))
    else:
      write_s("{} {}".format(x//2, y//2 + 1))
  else:
    write_s("-1 -1")


print_ans()