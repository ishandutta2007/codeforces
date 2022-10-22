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
    s = read_s()
    r_one = s.count('1')
    r_zero = s.count('0')
    l_one = 0
    l_zero = 0
    ans = len(s)
    for c in s:
        if c == '1':
            r_one -= 1
            l_one += 1
        else:
            r_zero -= 1
            l_zero += 1
        ans = min(ans, len(s) - max(l_one + r_zero, l_zero + r_one))
    write_i(ans)
print_ans()