t = int(input())
for _ in range(t):
    n = input()
    l = []
    for i in range(len(n)):
        if n[i] != '0':
            l.append(int(n[i]) * 10**(len(n) - 1 - i))
    print(len(l))
    print(*l)