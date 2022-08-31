i=input
i()
s=i()
t=i()
def go():
 if '*' not in s: return s!=t
 a,b=s.split('*')
 return len(a+b)>len(t) or not (t.startswith(a) and t.endswith(b))
print('YNEOS'[go()::2])