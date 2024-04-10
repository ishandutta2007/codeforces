n = input()
a = list(map(int, input().split()))
s = 0
for i in a:
    if i == 1:
        print('HARD')
        s = 1
        break
if s == 0:
    print('EASY')