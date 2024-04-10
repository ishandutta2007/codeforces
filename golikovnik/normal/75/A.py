a = int(input())
b = int(input())
res = a + b
modify = lambda x: ''.join([c if c != '0' else '' for c in x])
a = int(modify(str(a)))
b = int(modify(str(b)))
res = int(modify(str(res)))
print("YES" if a + b == res else "NO")