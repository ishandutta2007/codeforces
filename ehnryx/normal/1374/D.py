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

from itertools import groupby

T = read_i()
while T:
  T -= 1
  n = read_i()
  k = read_i()
  ans = max(
    [
      k - rem + 1 + k * (len(list(g)) - 1)
      for rem, g in groupby(
        sorted([read_i() % k for i in range(n)]))
      if rem != 0
    ],
    default = 0
  )
  write_i(ans)


print_ans()