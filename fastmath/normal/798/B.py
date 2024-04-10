inf = 10 ** 9

def get(s1, s2):
    for k in range(len(s)):
        new_v = s1[k: ] + s1[: k] 
        if (new_v == s2):
            return k
        
    return inf


n = int(input())
ans = inf
s = [''] * 50

for i in range(n):
    s[i] = input()

for i in range(len(s[0])):
    new = s[0][i: ] + s[0][: i]
    new_ans = i
    
    for j in range(1, n):
        new_ans += get(s[j], new)
        
    ans = min(ans, new_ans)
    
if ans >= inf:
    print(-1)
else:
    print(ans)