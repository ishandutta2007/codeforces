A = int(raw_input())
days = [int(x) for x in raw_input().split()]
i = 0
while (1):
    A -= days[i]
    if (A <= 0):
        break;
    i = (i + 1) % 7
print i + 1