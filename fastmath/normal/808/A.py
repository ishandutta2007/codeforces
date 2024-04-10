n = int(input())

c = int(str(n)[0])

print((c + 1) * (10 ** (len(str(n)) - 1)) - n)