n = int(input())
s = input()
ans = [0] * n

if n % 2:
    m = n // 2
    ans[m] = s[0]
    j = 1
    for i in range(1, m + 1):
        ans[m - i] = s[j]
        j += 1
        ans[m + i] = s[j]
        j += 1
else:
    m1 = (n - 1) // 2
    m2 = m1 + 1
    j = 0
    for i in range(m2):
        ans[m1 - i] = s[j]
        j += 1
        ans[m2 + i] = s[j]
        j += 1

print(''.join(map(str, ans)))