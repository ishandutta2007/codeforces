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
#### END FAST IO ####

T = read_i()
while T:
    T -= 1
    n = read_i()
    x = read_i()
    a = [read_i() for i in range(n)]
    cur = sum(a)
    if cur % x:
        write_i(n)
        continue
    left = 0
    for v in a:
        left += 1
        if v % x:
            break
    right = 0
    for v in reversed(a):
        right += 1
        if v % x:
            break
    n -= min(left, right)
    write_i(n if n else -1)
print_ans()