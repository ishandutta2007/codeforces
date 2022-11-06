n = int(input())
s = input()
new_s = [s[0]]
c = 0
for i in range(1, n):
    if new_s[-1] == s[i]:
        a = set('RGB')
        a.remove(s[i - 1])
        if i < n - 1:
            if s[i + 1] in a:
                a.remove(s[i + 1])
        new_s.append(next(iter(a)))
        c += 1
    else:
        new_s.append(s[i])
print(c)
print(''.join(new_s))