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
    x = read_i()
    a = [read_i() % 2 for i in range(n)]
    if x % 2:
        write_s("Yes" if a.count(1) and (x < n or a.count(1) % 2) else "No")
    else:
        write_s("Yes" if a.count(1) and a.count(0) and (x < n or a.count(1) % 2) else "No")
print_ans()