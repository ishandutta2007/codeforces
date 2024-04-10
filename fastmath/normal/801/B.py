def f(s1, s2):
    res = ['0'] * len(s1)
    for i in range(len(s1)):
        sim1 = ord(s1[i])
        sim2 = ord(s2[i])
        res[i] = chr(min(sim1, sim2))
        
    return ''.join(res)
    
s1 = input()
s2 = input()

if f(s1, s2) != s2:
    print(-1)
else:
    print(s2)