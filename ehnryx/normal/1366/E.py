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

from bisect import bisect

n = read_i()
m = read_i()
a = [read_i() for i in range(n)]
b = [read_i() for i in range(m)]
last = [-1 for i in range(2*m + 2)]
for i in range(n):
  v = bisect(b, a[i])
  a[i] = 2*v + 1 if v == 0 or a[i] > b[v-1] else 2*v
  last[a[i]] = i

MOD = 998244353
ans = int(last[1] == -1 and last[2] != -1)
for i in range(1, m):
  if last[2*i] == -1 or last[2*i+2] <= last[2*i]:
    ans = 0
  l = max(last[2*i], last[2*i+1])
  r = last[2*i+2]
  if l >= r:
    ans = 0
  else:
    ans = ans * (r-l) % MOD
write_i(ans)


print_ans()