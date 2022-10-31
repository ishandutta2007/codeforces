n,s=int(input()),input()
print(abs(sum(1 if x=='1' else 0 for x in s)-sum(1 if x=='0' else 0 for x in s)))