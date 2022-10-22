n = int(input())
m = 0
k = 0
for i in range(n):
    a, b = map(int, input().split())
    if a > b:
        m += 1
    if b > a:
        k += 1
if m > k:
    print('Mishka')
elif k > m:
    print('Chris')
else:
    print('Friendship is magic!^^')