n = int(input())
minprice = 10 ** 9
ans = 0
while n:
    n -= 1
    a, b = map(int, input().split())
    minprice = min(minprice, b)
    ans += a * minprice
print(ans)