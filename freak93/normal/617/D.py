A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

def out(value):
    print(value)
    exit(0)

if A[0] == B[0] and B[0] == C[0]:
    out(1)

if A[1] == B[1] and B[1] == C[1]:
    out(1)

import itertools

X = A
Y = B
Z = C
for p in itertools.permutations([X, Y, Z]):
    A = p[0]
    B = p[1]
    C = p[2]
    if A[0] == B[0] and (C[1] <= min(A[1], B[1]) or C[1] >= max(A[1], B[1])):
        out(2)
    if A[1] == B[1] and (C[0] <= min(A[0], B[0]) or C[0] >= max(A[0], B[0])):
        out(2)

out(3)