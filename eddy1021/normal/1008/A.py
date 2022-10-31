s=input()
print('YES'if s[-1]in"aeioun"and all(s[i] in "aeioun" or s[i+1] in "aeiou" for i in range(len(s)-1))else'NO')