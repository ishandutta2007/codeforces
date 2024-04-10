n = int(input())
a = [int(i) for i in input().split()]
fives = a.count(5)
zeros = n - fives
if zeros == 0:
    print(-1)
    exit(0)
if fives < 9:
    print(0)
    exit(0)
print('5' * (fives // 9 * 9) + '0' * zeros)