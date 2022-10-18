__author__ = 'Fdg'

def change(a):
    if a>='a' and a<='z': return str(a).upper()
    return str(a).lower()

def upper(a):
    return a>='A' and a<='Z'

s=raw_input()
ok=1
res=""
for i in range(1,len(s)):
    if not upper(s[i]): ok=0
if ok:
    for i in range(len(s)):
        res+=change(s[i])
else: res=s
print(res)