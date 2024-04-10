import math
import sys
input = sys.stdin.readline
 
def solve():
 
  n = int(input())
  a = [int(x) for x in input().split()]
  
  for i in range(1, n - 1):
    if a[i - 1] != a[i] and a[i] != a[i + 1]:
      print(i + 1)
      return
  
  if a[0] != a[1]:
    print("1")
  else:
    print(n) 
 
T = int(input())
 
while(T):
  solve()
  T -= 1