s=input()
print('YES' if any(len(set(s[i:i+7]))==1 for i in range(len(s)-6)) else 'NO')