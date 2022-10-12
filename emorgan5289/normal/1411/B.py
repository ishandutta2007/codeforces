import os

if os.environ.get("USERNAME") == "Ethan":
    input = open("../../input.in", "r").readline

t = int(input())
for _ in range(t):
    n = int(input())
    while 1:
        x = n
        ok = True
        while x > 0:
            ok = ok and (x%10 == 0 or n%(x%10) == 0)
            x //= 10
        if ok: break
        n += 1
    print(n)