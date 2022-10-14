import sys
input = sys.stdin.readline

n = int(input())
l, r = 1, n - 1

while l < r:
    k = r // n + 1
    c = n * k - (r - (r - l) // 2)
    print('+', c, flush=True)
    l += c
    r += c
    k = int(input())
    if l // n == k:
        r = k * n + n - 1
    else:
        l = k * n

print('!', l, flush=True)