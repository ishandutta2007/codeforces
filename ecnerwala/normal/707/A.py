n,m = map(int, input().split())
a = '\n'.join(input() for i in range(n))
a = set(a)
print("#Color" if a & set('CMY') else '#Black&White')