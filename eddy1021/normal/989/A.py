s=input()
print('Yes'if any(sorted(s[i:i+3])==['A','B','C'] for i in range(len(s)))else'No')