t = int(input())

for u in range(t):
    a = int(input())
    ans = 0
    b = '1' * len(str(a))
    ans = a // int(b)
    while(a > 9):
        a //= 10
        ans += 9
    print(ans)