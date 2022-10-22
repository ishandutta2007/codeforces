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
  s = read_s()
  t = read_s()
  if sorted(s) != sorted(t):
    write_i(-1)
    continue

  s_count = [[0 for i in range(n+1)] for j in range(26)]
  t_count = [[0 for i in range(n+1)] for j in range(26)]
  for i in range(n):
    for j in range(26):
      s_count[j][i] = s_count[j][i-1]
      t_count[j][i] = t_count[j][i-1]
    s_count[ord(s[i]) - ord('a')][i] += 1
    t_count[ord(t[i]) - ord('a')][i] += 1

  dp = [[0 for i in range(n+1)] for j in range(n+1)]
  for i in range(0, n):
    for j in range(i, n):
      dp[i][j] = dp[i-1][j] + 1
      if s[i] == t[j]:
        dp[i][j] = min(dp[i][j], dp[i-1][j-1])
      c = ord(t[j]) - ord('a')
      if s_count[c][i] < t_count[c][j]:
        dp[i][j] = min(dp[i][j], dp[i][j-1])
  write_i(dp[n-1][n-1])

print_ans()