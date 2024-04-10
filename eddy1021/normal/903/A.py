for i in range(int(input())):
  x=int(input())
  print('YES'if any((3*i+7*j==x for i in range(100) for j in range(100)))else'NO')