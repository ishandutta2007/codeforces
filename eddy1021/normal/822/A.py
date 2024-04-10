def fac(a): return 1 if a == 1 else a * fac(a-1)
print(fac(min(list(map(int,input().split())))))