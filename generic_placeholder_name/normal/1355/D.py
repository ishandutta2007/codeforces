#It's about time I ACed this
import sys
input = sys.stdin.readline

n, s = [int(x) for x in input().split()]
ans = [2] * (n - 1)
ans.append(s - 2 * n + 2)

if s >= 2 * n:
    print('YES')
    print(*ans)
    print(1)
else:
    print('NO')