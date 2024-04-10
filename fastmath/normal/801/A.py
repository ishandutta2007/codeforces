def get(s):
    res = 0
    for i in range(len(s) - 1):
        if s[i] == 'V' and s[i + 1] == 'K':
            res += 1
            
    return res


s = input()
l = list(s)

ans = 0
for i in range(len(l)):
    st = l[i]
    
    l[i] = 'V'
    ans = max(ans, get(''.join(l)))
    
    l[i] = 'K'
    ans = max(ans, get(''.join(l)))
    
    l[i] = st
    
print(ans)