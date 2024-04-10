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

T = read_i()
while T:
  T -= 1
  n = read_i()
  s = read_s()
  head = []
  tail = []
  for c in s:
    if c == "1":
      break
    head.append(c)
  for c in reversed(s):
    if c == "0":
      break
    tail.append(c)
  if len(head) + len(tail) == len(s):
    write_s(s)
  else:
    write_s("".join(head) + "0" + "".join(tail))


print_ans()