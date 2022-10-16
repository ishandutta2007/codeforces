def change(n):
  while n and not n % 2:
    n /= 2
  while n and not n % 3:
    n /= 3
  return n

n = int(input())
a = [int(i) for i in input().split()]
a = [change(i) for i in a]
print("Yes" if len(set(a)) == 1 else "No")