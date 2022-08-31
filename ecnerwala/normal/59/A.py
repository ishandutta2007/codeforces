s=input()
print(s.upper()if sum(c.isupper()for c in s)*2>len(s)else s.lower())