n = int(input())
a = b = 0
while n:
    n -= 1
    x, y = map(int, input().split())
    if x > y:
        a += 1
    elif x < y:
        b += 1
if a > b:
    print("Mishka")
elif a < b:
    print("Chris")
else:
    print("Friendship is magic!^^")