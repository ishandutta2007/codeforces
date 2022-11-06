def fac(n):
    return 1 if n < 2 else fac(n - 1) * n

s1 = input()
s2 = input()

pos = sum(1 if c == '+' else -1 for c in s1)
posact = sum(1 if c == '+' else -1 for c in s2 if c != '?')
numq = sum(1 for c in s2 if c == '?')
diff = abs(pos - posact)
if diff > numq or (numq - diff) % 2 == 1:
    print(0.0)
    exit(0)

fixed = diff + (numq - diff) // 2
print(fac(numq) / fac(fixed) / fac(numq - fixed) / 2**numq)