n = int(input())
ans = 'NO'
for i in range(n):
    s = input()
    i = 0
    while s[i] != ' ':
        i += 1
    j = i+1
    while s[j] != ' ':
        j += 1
    before = int(s[i+1:j])
    after = int(s[j+1:])
    if after - before > 0 and before >= 2400:
        ans = 'YES'
print(ans)