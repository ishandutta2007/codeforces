def f(n):
    i = (n // 50) % 475
    for j in range(25):
        i = (i * 96 + 42) % 475
        if i + 26 == p:
            return True
        
    return False

p, x, y = map(int, input().split())
k = 0
can = False

i = x
while i - 50 >= y:
    i -= 50
    if f(i):
        print(0)
        can = True
        break

if not can:
    for i in range(x, x + 30001, 50):
        if f(i):
            print(k)
            break
        
        if not (i - x) % 100:
            k += 1