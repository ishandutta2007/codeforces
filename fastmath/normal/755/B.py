n, m = map(int, input().split())

my_set = set()
for i in range(n):
    s = input()
    my_set.add(s)
    
double = 0
for i in range(m):
    s = input()
    if s in my_set:
        double += 1
        
n -= double
m -= double
while True:
    if not double and not n:
        print('NO')
        break
    elif double:
        double -= 1
    else:
        n -= 1
    
    if not double and not m:
        print('YES')
        break
    elif double:
        double -= 1
    else:
        m -= 1