n = int(input())
s = input()

d = dict()
d['A'] = 0
d['C'] = 0
d['G'] = 0
d['T'] = 0
d['?'] = 0
for i in range(n):
    d[s[i]] += 1
    
mx = max(d['A'], d['C'], d['G'], d['T'])
r = mx * 4 - (d['A'] + d['C'] + d['G'] + d['T'])

if r > d['?'] or ((d['?'] - r) % 4):
    print('===')
else:
    ans = [0] * n
    ans = list(s)
    
    i = 0
    while mx - d['A']:
        if s[i] == '?':
            ans[i] = 'A'
            d['A'] += 1
        i += 1
        
    while mx - d['C']:
        if s[i] == '?':
            ans[i] = 'C'
            d['C'] += 1
        i += 1    
        
    while mx - d['G']:
        if s[i] == '?':
            ans[i] = 'G'
            d['G'] += 1
        i += 1    
        
    while mx - d['T']:
        if s[i] == '?':
            ans[i] = 'T'
            d['T'] += 1
        i += 1        
        
    s1 = 'ACGT'
    j = 0
    while i < n:
        if s[i] == '?':
            ans[i] = s1[j]
            j = (j + 1) % 4
        i += 1               
        
    print(''.join(map(str, ans)))