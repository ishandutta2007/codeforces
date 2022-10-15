C = sum(map(int, raw_input().split()))
M = sum(map(int, raw_input().split()))
N = input()

if ((M - 1) / 10) + 1 + ((C - 1) / 5) + 1 <= N:
    print 'YES'
else:
    print 'NO'