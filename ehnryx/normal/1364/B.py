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
    a = [read_i(), read_i()]
    for i in range(2, n):
        v = read_i()
        if (a[-2] - a[-1]) * (a[-1] - v) >= 0:
            a[-1] = v
        else:
            a.append(v)
    write_i(len(a))
    write_s(' '.join([str(x) for x in a]))

print_ans()