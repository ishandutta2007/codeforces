__author__ = 'Fdg'
s=raw_input()
s=s.lower()
ans=""
cons=['a','o','i','e','u','y']
for i in range(len(s)):
    if s[i] not in cons:
        ans+='.'+s[i]
print(ans)