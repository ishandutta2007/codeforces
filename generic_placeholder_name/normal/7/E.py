def helper(s, d):
    if s in d:
        return d[s]

    cnt = 0
    for idx, c in reversed(list(enumerate(s))):
        if c == ')':
            cnt += 1
        elif c == '(':
            cnt -= 1
        if cnt == 0 and c in ['+', '-']:
            s1 = s[0:idx]
            s2 = s[idx+1:]
            t1 = helper(s1, d)
            t2 = helper(s2, d)
            t = 3
            if t1 == 2 or t2 == 2:
                t = 2
            elif t2 == 3 and c == '-':
                t = 2
            d[s] = t
            return t

    cnt = 0
    for idx, c in reversed(list(enumerate(s))):
        if c == ')':
            cnt += 1
        elif c == '(':
            cnt -= 1
        if cnt == 0 and c in ['*', '/']:
            s1 = s[0:idx]
            s2 = s[idx+1:]
            t1 = helper(s1, d)
            t2 = helper(s2, d)
            # print(s)
            # print(s1, '    ', s2)
            t = 4
            if t1 == 2 or t2 == 2:
                t = 2
            elif t1 == 3 or t2 == 3:
                t = 2
            elif t2 == 4 and c == '/':
                t = 2
            d[s] = t
            return t

    if s[0] == '(' and s[-1] == ')':
        if helper(s[1:-1], d) == 2:
            return 2
        else:
            return 1

    d[s] = 1
    return 1


d = {}
n = int(input())
for i in range(0, n):
    temp = input()
    j = 0
    while temp[j] != '#':
        j += 1
    while temp[j] != 'd':
        j += 1
    j += 6
    temp = temp[j:].strip()
    arr = temp.split(' ', 1)
    name, exp = arr[0], ''.join(arr[1].split())
    t = helper(exp, d)
    d[name] = t
final = ''.join(input().split())
res = helper(final, d)
print(['OK', 'Suspicious'][res == 2])