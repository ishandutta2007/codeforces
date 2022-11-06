n, b, a = map(int, input().split())
s = list(map(int, input().split()))
max_b, max_a = b, a

i = 0
while i < n and (a > 0 or b > 0):
    i += 1
    if s[i - 1] == 1:
        if a < max_a and b > 0:
            a += 1
            b -= 1
        else:
            a -= 1
    else:
        if a > 0:
            a -= 1
        else:
            b -= 1

print(i)