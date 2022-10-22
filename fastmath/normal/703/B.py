n, k = map(int, input().split())
prices = list(map(int, input().split()))
st = list(map(int, input().split()))
for i in range(k):
    st[i] -= 1
ans = 0
used = 0
useds = set()
s = sum(prices)
for i in range(n):
    ans += prices[i] * prices[i - 1]
for i in range(k):
    ans += s * prices[st[i]] - prices[st[i]] * used
    ans -= prices[st[i]] * (prices[st[i]] + prices[st[i] - 1] + prices[(st[i] + 1) % n])
    if (st[i] - 1) % n in useds:
        ans += prices[st[i]] * prices[st[i] - 1]
    if (st[i] + 1) % n in useds:
        ans += prices[st[i]] * prices[(st[i] + 1) % n]    
    used += prices[st[i]]
    useds.add(st[i])
print(ans)