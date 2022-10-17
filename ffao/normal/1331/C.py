n = bin(int(input()))[2:].zfill(6)

p = [0, 5, 3, 2, 4, 1]

print(int(''.join(n[t] for t in p),2))