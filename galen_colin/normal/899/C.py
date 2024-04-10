n = int(input())

v = int(n * (n + 1) / 2)
print(v % 2)
targ = int(v / 2)

seq = []
for i in range(n, 0, -1):
  if (targ >= i):
    targ -= i
    seq.append(i)

print(len(seq), end = " ")
[print(seq[i], end = " ") for i in range(len(seq))]