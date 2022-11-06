n, m = (int(s) for s in input().split(' '))
a = [int(s) for s in input().split(' ')]
probs = {}
for i in a:
    if i in probs:
        probs[i] += 1
        print('0', end='')
    else:
        probs[i] = 1
        if len(probs) == n:
            print('1', end='')
            probs = {k: v - 1 for k, v in probs.items() if v > 1}
        else:
            print('0', end='')
print()