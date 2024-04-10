def gcd(x, y):
    while y > 0:
        x, y = y, x % y
    return x

t, w, b = map(int, raw_input().split())

mx = w * b // gcd(w, b)
cnt = min(w, b) * (t // mx) - 1
if t % w == t % b:
    cnt += 1
cnt += min(min(w, b), t % mx)

g = gcd(cnt, t)
res = str(cnt / g) + "/" + str(t / g)
print res