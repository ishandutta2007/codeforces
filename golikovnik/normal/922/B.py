n = int(input())
ans = 0
for a in range(1,n+1):
    for b in range(a,n+1):
        c = a^b
        if c < b or c > n:
            continue
        if c < a+b:
            ans += 1
print(ans)