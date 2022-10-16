n = input()
s = ""
flag = False
for c in n:
  if flag:
    s += "1"
    continue
  if c in ["0", "1"]:
    s += c
  else:
    s += "1"
    flag = True
s = int(s, 2)
print(s)