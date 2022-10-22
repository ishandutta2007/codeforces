N = int(input())
A = ''.join(input().split())

A = A.split('1')
if len(A) == 1:
    print(0)
    exit(0)
A = A[1:-1]
answer = 1
for x in A:
    answer *= len(x) + 1

print(answer)