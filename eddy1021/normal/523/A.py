w,h = input().split()
w,h = int(w),int(h)
S = []
for i in range(0,h):
    ts = input()
    S += [ts]
for i in range(0,2*w):
    idxi = i // 2
    tans = ""
    for j in range(0,2*h):
        idxj = j // 2
        tans += S[idxj][idxi]
    print(tans)