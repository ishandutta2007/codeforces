def lol():
    ans = INF
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i == j or j == k or k == i:
                    continue
                
                a, b, c = INF, INF, INF
                for i1 in range(m):
                    if 48 <= ord(s[i][i1]) <= 57 or 48 <= ord(s[i][-i1]) <= 57:
                        a = min(a, i1)
                
                    if 97 <= ord(s[j][i1]) <= 122 or 97 <= ord(s[j][-i1]) <= 122:
                        b = min(b, i1)             
                
                    if s[k][i1] in sim or s[k][-i1] in sim:
                        c = min(c, i1) 
                        
                    if a < INF and b < INF and c < INF:
                        break
                    
                ans = min(ans, a + b + c) 
    return ans


n, m = map(int, input().split())

INF = 10 ** 9
s = [0] * n
sim = ['*', '&', '#']
for i in range(n):
    new = input()
    s[i] = new + new

ans = lol()
            
if ans >= INF:
    print(-1)
else:
    print(ans)