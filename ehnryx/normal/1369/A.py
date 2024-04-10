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
  write_s("YES" if n%4 == 0 else "NO")


print_ans()