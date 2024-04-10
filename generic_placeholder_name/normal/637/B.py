n = int(input())
s = set()
a = []
for x in [input() for i in range(n)][::-1]:
    if not (x in s): 
        a += [x] 
        s |= {x}
print('\n'.join(a))