a = int(input())
for i in range(a):
    n = int(input())
    if n >= 4 and n % 2 == 0:
        print(0)
    if n >= 4 and n % 2 == 1:
        print(1)
    if n < 4:
        print(4 - n)