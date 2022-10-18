r = input
n = int(r())
b = list(map(int, r().split()))
b2 = list(map(int, r().split()))
x = b[1] * b[2] * b2[2]
abc = int(x ** 0.5)
while abc**2 < x:
  abc += 1
while abc**2 > x:
  abc -= 1
a = [0] * n
a[0] = abc // b2[2]
a[1] = abc // b[2]
a[2] = abc // b[1]
for i in range(3, n):
    a[i] = b[i] // a[0]
print(' '.join(map(str, a)))