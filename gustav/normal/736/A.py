f = [1, 2, 3]

while f[-1] < 10 ** 18:
    f.append(f[-2] + f[-1])

n = int(input())
sol = 1
while f[sol + 1] <= n:
    sol += 1

print(sol)