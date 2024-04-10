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
  n, x, m = [read_i() for i in range(3)]
  left = x
  right = x
  for i in range(m):
    l = read_i()
    r = read_i()
    if left <= r and l <= right:
      left = min(left, l)
      right = max(right, r)
  write_i(right - left + 1)

print_ans()