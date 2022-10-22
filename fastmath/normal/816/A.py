def f():
    global a, b
    if a == '23' and b == '59':
        a = '00'
        b = '00'
        return
    
    if b == '59':
        a = str(int(a) + 1)
        if len(a) == 1:
            a = '0' + a
            
        b = '00'
        return
    
    b = str(int(b) + 1)
    if len(b) == 1:
        b = '0' + b


def f1(s):
    res = ''
    for i in range(len(s)):
        res += s[len(s) - i - 1]
        
    return res


s = input()
a = s[:2]
b = s[3:]

ans = 0
while a + b != f1(b) + f1(a):
    f()
    ans += 1
    
print(ans)