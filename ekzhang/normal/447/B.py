from string import ascii_lowercase as letters

def getAns(s, k, chars):
    ans = 0
    for i in xrange(len(s)):
        ans += (i + 1) * chars[letters.index(s[i])]
    ans += max(chars) * ((len(s) + k) * (len(s) + k + 1) / 2 - len(s) * (len(s) + 1) / 2)
    return ans

S = raw_input()
K = input()
chars = map(int, raw_input().split())
print getAns(S, K, chars)