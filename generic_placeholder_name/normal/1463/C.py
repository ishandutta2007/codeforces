def solve_case():
    n = int(input())
    curr = 0
    t, x = map(int, input().split())
    goal = x
    ans = 0
    a = [[t, x, curr]]
    for q in range(n - 1):
        t, x = map(int, input().split())
        r = t - a[-1][0]
        if curr > goal:
            curr = max(curr - r, goal)
        else:
            curr = min(curr + r, goal)
        if max(curr, a[-1][2]) >= a[-1][1] >= min(curr, a[-1][2]):
            ans += 1
        if curr == goal:
            goal = x
        a.append([t, x, curr])
    if min(curr, goal) <= a[-1][1] <= max(curr, goal):
        ans += 1
    print(ans)

def main():
    for _ in range(int(input())):
        solve_case()

main()