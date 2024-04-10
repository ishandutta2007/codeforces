def cap(s):
    if s[0] >= 'a' and s[0] <= 'z':
        s = chr(ord(s[0]) + ord('A') - ord('a')) + s[1:]
    return s

print(cap(input()))