n = int(input())
ans = ''
for i in range(n // 4):
    ans += 'aabb'

if n % 4 == 1:
    ans += 'a'

if n % 4 == 2:
    ans += 'aa'
    
if n % 4 == 3:
    ans += 'aab'
    
print(ans)