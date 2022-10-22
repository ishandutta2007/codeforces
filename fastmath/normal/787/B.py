n, m = map(int, input().split())

ans = 'NO'
for i in range(m):
    a = list(map(int, input().split()))[1: ]
    s = set()
    new_ans = False
    for j in range(len(a)):
        s.add(a[j])
        if -a[j] in s:
            new_ans = True
            break
    
    if not new_ans:
        ans = 'YES'
        break

print(ans)