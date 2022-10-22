g = ['A', 'E', 'I', 'O', 'U', 'Y']
s = input() + 'A'
l = -1
ans = 0
for i in range(len(s)):
    if s[i] in g:
        ans = max(ans, i - l)
        l = i
print(ans)