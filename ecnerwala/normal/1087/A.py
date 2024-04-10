s = input()
p = (len(s)+1)//2
a,b = s[:p],s[p:]
print(''.join(x+y for x,y in zip(a[::-1],b+' ')))