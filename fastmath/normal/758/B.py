s = input()

for i in range(len(s)):
    if s[i] == 'B':
        b = i % 4
    elif s[i] == 'Y':
        y = i % 4
    elif s[i] == 'R':
        r = i % 4
    elif s[i] == 'G':
        g = i % 4

b_ans = 0
y_ans = 0
r_ans = 0
g_ans = 0
for i in range(len(s)):
    if s[i] == '!':
        if i % 4 == b:
            b_ans += 1
        elif i % 4 == y:
            y_ans += 1
        elif i % 4 == r:
            r_ans += 1            
        elif i % 4 == g:
            g_ans += 1    

print(r_ans, b_ans, y_ans, g_ans)