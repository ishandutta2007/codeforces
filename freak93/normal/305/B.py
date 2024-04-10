P, Q = [int(x) for x in input().split()]

N = int(input())
A = [int(x) for x in input().split()]

U, V = 1, 0
for x in A[::-1]:
    U, V = V, U
    U, V = V * x + U, V

if U * Q == P * V:
    print("YES")
else:
    print("NO")