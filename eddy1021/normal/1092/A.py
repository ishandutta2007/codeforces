for _ in range(int(input())):
  n,k=list(map(int, input().split()))
  print(''.join(chr(i%k+97) for i in range(n)))