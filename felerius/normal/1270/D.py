# Contest: Good Bye 2019 (https://codeforces.com/contest/1270)
# Problem: D: Strange Device (https://codeforces.com/contest/1270/problem/D)

def rint():
    return int(input())


def rints():
    return list(map(int, input().split()))


def ask(pos):
    print('?', *map(str, pos), flush=True)
    return rints()


n, k = rints()
rng = set(range(1, k + 1))
i, ai = ask(rng)
ai2 = ask(list(rng - {i}) + [k + 1])[1]
cmp = ai2 < ai
cnt = 0
for j in range(1, k + 1):
    if j == i:
        continue
    elem_cmp = cmp
    if ai != ask(list(rng - {j}) + [k + 1])[1]:
        elem_cmp = not elem_cmp
    cnt += elem_cmp
print(f'! {cnt + 1}')