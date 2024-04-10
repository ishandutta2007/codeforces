def get(a, b, c):
    return a + b * 26 + c * 676

def conv(a):
    return chr(a + ord('a'))

def rconv(a):
    return ord(a) - ord('a')

s = str(input())
n = len(s)
ask = [[x % 26, (x // 26) % 26, (x // 26 // 26) % 26] for x in range(n)]
receive = ask
for i in range(3):
    out = [conv(ask[j][i]) for j in range(n)]
    print("? " + "".join(out), flush=True)
    res = str(input())
    for j in range(n):
        receive[j][i] = rconv(res[j])
ans = [""] * n
for i in range(n):
    ans[get(receive[i][0], receive[i][1], receive[i][2])] = s[i]
print("! " + "".join(ans), flush=True)