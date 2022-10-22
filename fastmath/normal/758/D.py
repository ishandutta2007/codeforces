def check(i, new, s):
    d = ''
    while i >= 0 and not (int(s[i])):
        d = s[i] + d
        i -= 1

    if i >= 0:
        d = s[i] + d
    if int(d + new) >= n:
        return ''
    return d
    

n = int(input())
s = input()

m = []
i = len(s) - 1
while i >= 0:
    new = s[i]
    i -= 1
    add = check(i, new, s)
    while i >= 0 and add:
        new = add + new
        i -= len(add)
        add = check(i, new, s)
        
    m.append(int(new))

l = len(m)
for i in range(l // 2):
    m[i], m[l - i - 1] = m[l - i - 1], m[i]
    
ans = 0
for i in range(l):
    ans += m[i] * (n ** (l - i - 1))

print(ans)