def f(x): return x if x % 2 else x - 1
input()
print(' '.join(str(f(int(k))) for k in input().split()))