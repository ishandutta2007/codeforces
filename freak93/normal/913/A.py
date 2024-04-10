N = int(input())
M = int(input())

if N > 50:
    print(M)
else:
    print(M % (2**N))