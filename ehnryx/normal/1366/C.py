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
  m = read_i()
  a = [[read_i() for j in range(m)] for i in range(n)]
  L = 0
  R = n-1 + m-1
  ans = 0
  while L < R:
    count = [0, 0]
    for i in range(n):
      for j in range(m):
        if i + j == L or i + j == R:
          count[a[i][j]] += 1
    ans += min(count)
    L += 1
    R -= 1
  write_i(ans)

print_ans()