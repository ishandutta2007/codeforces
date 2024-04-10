import sys

#sys.stdin = open('in.txt', 'rt')

a = list(map(int, input().split()))
s = input().strip()
w = [(0, -1)]
sum = 0
for i in enumerate(s):
    sum += a[ord(i[1]) - ord('a')]
    w.append((sum, i[0]))
w.sort()
dp = [0] * 26
answer = 0
for i in enumerate(w):
    if i[0] >= 1 and i[1][0] != w[i[0] - 1][0]:
        dp = [0] * 26
    if i[1][1] >= 0:
        dp[ord(s[i[1][1]]) - ord('a')] += 1
    if i[1][1] < len(s) - 1:
        answer += dp[ord(s[i[1][1] + 1]) - ord('a')]
print(answer)