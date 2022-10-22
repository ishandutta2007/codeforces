import sys

inf = 10**9 + 7

def solve():
    def check(mid):
        tot = n + mid
        dif = 0
        solved = cnt[:]

        for i in range(5):
            if v[i] != -1 and p[i] != -1 and p[i] < v[i]:
                solved[i] += mid

        for i in range(5):
            if solved[i]*2 > tot:
                max_score = 500
            elif solved[i]*4 > tot:
                max_score = 1000
            elif solved[i]*8 > tot:
                max_score = 1500
            elif solved[i]*16 > tot:
                max_score = 2000
            elif solved[i]*32 > tot:
                max_score = 2500
            else:
                max_score = 3000

            if v[i] == p[i]:
                pass
            elif v[i] == -1:
                dif += max_score * (250 - p[i]) // 250
            elif p[i] == -1:
                dif += -max_score * (250 - v[i]) // 250
            else:
                dif += max_score * (-p[i] + v[i]) // 250

        # print(mid, dif)

        return dif < 0

    n = int(sys.stdin.readline())

    cnt = [0]*5

    v = [int(i) for i in sys.stdin.readline().split()]

    for i in range(5):
        if v[i] != -1:
            cnt[i] += 1

    p = [int(i) for i in sys.stdin.readline().split()]

    for i in range(5):
        if p[i] != -1:
            cnt[i] += 1

    for i in range(n - 2):
        a = [int(ai) for ai in sys.stdin.readline().split()]

        for j in range(5):
            if a[j] != -1:
                cnt[j] += 1

    for i in range(6000):
        if check(i):
            print(i)
            return

    print(-1)

if __name__ == '__main__':
    solve()