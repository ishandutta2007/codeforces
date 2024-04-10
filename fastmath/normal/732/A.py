k, r = map(int, input().split())
for i in range(1, 11):
    if not (k * i) % 10 or ((k * i) >= r and (k * i) % 10 == r % 10):
        ans = i
        break
print(ans)