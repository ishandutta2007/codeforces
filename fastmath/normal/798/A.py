def check(s):
    for i in range(len(s)):
        if s[i] != s[len(s) - i - 1]: return False
        
    return True


s = input()
ans = 'NO'
for i in range(len(s)):
    for j in range(26):
        if chr(97 + j) == s[i]: continue
        new = s[: i] + chr(97 + j) + s[i + 1: ]
        if check(new):
            ans = 'YES'
            break
    
print(ans)