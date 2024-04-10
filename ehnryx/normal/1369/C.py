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
  k = read_i()
  a = sorted([read_i() for i in range(n)])
  w = sorted([read_i() for i in range(k)])
  ones = w.count(1)
  ans = sum(a[-k:])
  if ones: ans += sum(a[-ones:])
  pos = 0
  for i in reversed(w):
    if i == 1: break
    ans += a[pos]
    pos += i - 1
  write_i(ans)


print_ans()