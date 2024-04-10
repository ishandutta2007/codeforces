for t in range(int(input())):
    n = int(input())
    a = [(int(x), i) for i, x in enumerate(input().split(' '))]
    a.sort()
    p = [x[0] for x in a]
    for i in range(1, len(p)):
        p[i] += p[i-1]
    ans = [a[-1][1]]
    for i in range(len(p)-1, 0, -1):
        if a[i][0] <= p[i-1]:
            ans.append(a[i-1][1])
        else:
            break
    print(len(ans))
    print(' '.join(str(x+1) for x in sorted(ans)))