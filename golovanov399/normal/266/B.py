ID = input().split()
n = int(ID[0])
k = int(ID[1])
s = input()
t = ""
for _ in range(k):
    i = 0
    while (i < n):
        if (i == n - 1):
            t += s[i]
        elif (s[i] == 'B' and s[i + 1] == 'G'):
            t += s[i + 1] + s[i]
            i += 1
        else:
            t += s[i]
        i += 1
    s = t
    t = ""

print(s)