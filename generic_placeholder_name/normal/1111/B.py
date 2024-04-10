#"Clearing really easy shit", episode 3
import sys
input = sys.stdin.readline

n, k, m = [int(x) for x in input().split()]
a = sorted([int(x) for x in input().split()])
s = sum(a)
mx = (s + min(m, n * k)) / n;

for i in range(min(m, n - 1)):
    s -= a[i]
    mx = max(mx, (s + min(m - i - 1, (n - i - 1) * k)) / (n - i - 1))
    
print(mx)