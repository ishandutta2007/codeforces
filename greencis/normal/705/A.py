n = int(input())
s = ""
for i in range(n):
    if i % 2 == 0:
        s += 'I hate '
    else:
        s += 'I love '
    if i == n - 1:
        s += 'it'
    else:
        s += 'that '
print(s)