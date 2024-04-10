def f(s):
    s = list(s)
    for i in range(len(s)):
        if s[i] == '?':
            s[i] = 'A'
    res = ''
    for i in range(len(s)):
        res += s[i]
    return res

    
s = input()
n = len(s)
d = dict()
for i in range(26):
    d[chr(i + 65)] = i
ans = 0
for i in range(25, n):
    ko = []
    k = 0
    a = [0] * 26
    for j in range(26):
        if s[i - j] != '?':
            a[d[s[i - j]]] += 1
        else:
            k += 1
            
    for j in range(26):
        if not a[j]:
            ko.append(chr(j + 65))
            
    if k >= len(ko):
        new = s[i - 25: i + 1]
        for j in range(26):
            if new[j] == '?':
                new = new[:j] + ko[-1] + new[j + 1:]
                ko.pop()
        print(f(s[:i - 25:]) + new + f(s[i + 1:]))
        ans = 1
        break
if not ans:
    print(-1)