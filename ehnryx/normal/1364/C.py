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

n = read_i()
a = [read_i() for i in range(n)]
need = [i != a[-1] for i in range(n+1)]
ans = [-1 for i in range(n)]
for i in range(n):
    if i > 0 and a[i] != a[i-1]:
        ans[i] = a[i-1]
        need[ans[i]] = False

j = 0
for i in range(n):
    if ans[i] == -1:
        while not need[j]:
            j += 1
        ans[i] = j
        need[j] = False

write_s(' '.join([str(x) for x in ans]))
print_ans()