t = int(input())
for _ in range(t):
    s = input()
    if len(set(s)) < 2:
        print(-1)
    else:
        print(''.join(sorted(s)))