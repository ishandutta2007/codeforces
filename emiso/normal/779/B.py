n, k = raw_input().split()
k = int(k)

resp = 0
seq = 0
nn = n[::-1]

for i in nn:
    if i == '0':
        seq += 1
        if seq == k:
            print resp
            exit(0)
    else:
        resp += 1

print len(n) - 1