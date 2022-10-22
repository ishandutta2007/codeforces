n = int(input())
s = input()
s += 'W'
a = []
k = 0
for i in range(n + 1):
    if s[i] == 'B':
        k += 1
    elif i and s[i - 1] == 'B':
        a.append(k)
        k = 0
print(len(a))
if len(a) > 0:
    print(' '.join(map(str, a)))