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
    answer_list.append(v.encode())
def write_i(v):
    write_s(str(v))
def print_ans():
    os.write(1, "\n".encode().join(answer_list))
#### END FAST IO ####

T = read_i()
while T:
    T -= 1
    n = read_i()
    ans = 0
    cur = 0
    for v in sorted([read_i() for i in range(n)]):
        cur += 1
        if cur >= v:
            ans += 1
            cur = 0
    write_i(ans)
print_ans()