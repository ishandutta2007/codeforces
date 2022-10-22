def f(n):
    ans = 0
    while n:
        ans += n%10
        n //= 10
    return ans

def get(n, k):
    ans = 0
    for i in range(k+1):
        ans += f(n+i)
    return ans

t = int(input())
for tmp in range(t):
    w, k = map(int, input().split())

    ans = -1
    for last in range(10):
        c9 = 0
        while last + c9 * 9 <= w:
            st = '9' * c9 + str(last)
            stx = int(st)
            h = get(stx, k)
            if h <= w and (w - h) % (k + 1) == 0:
                ost = (w - h) // (k + 1)

                pref = ''
                while ost > 0:
                    if ost >= 9:

                        if len(pref) == 0:
                            pref += '8'
                            ost -= 8
                        else:
                            pref += '9'
                            ost -= 9

                    else:
                        pref += str(ost)    
                        break
                pref = pref[::-1]

                s = pref + '9' * c9 + str(last)
                x = int(s)

                if get(x, k) == w:
                    if ans == -1 or x < ans:
                        ans = x

            c9 += 1

    print(ans)