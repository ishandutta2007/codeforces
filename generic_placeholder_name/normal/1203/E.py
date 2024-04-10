#On this episode of "Clearing really easy shit that I somehow failed to do"
import sys
input = sys.stdin.readline

N = 150002
a, b = [0] * N, [0] * N

_ = input()
for x in input().split():
    a[int(x)] += 1

for i in range(1, N - 1):
    while a[i]:
        a[i] -= 1
        if i > 1 and not b[i - 1]:
            b[i - 1] = 1
        elif not b[i]:
            b[i] = 1
        else:
            b[i + 1] = 1
        
print(sum(b))