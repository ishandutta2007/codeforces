for _ in range(int(input())):
  s=sorted(input())
  print('Yes'if len(s)==len(set(s)) and ord(s[0])+len(s)-1==ord(s[-1])else'No');