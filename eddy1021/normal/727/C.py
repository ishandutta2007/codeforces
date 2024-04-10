import sys
def ask(a, b):
  print('?', a, b)
  sys.stdout.flush()
  return int(input())
n = int(input())
a = [0 for i in range(n+1)]
a12 = ask(1, 2)
a13 = ask(1, 3)
a23 = ask(2, 3)
s = (a12+a13+a23)//2
a[1], a[2], a[3] = s-a23, s-a13, s-a12
for i in range(3, n):
  a[i+1]=ask(1,i+1)-a[1]
a[0]='!'
print( " ".join(str(x) for x in a) )
sys.stdout.flush()