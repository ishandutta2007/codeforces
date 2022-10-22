n = int(input())
a = list(map(int, input().split()))
if a[-1] == 0:
    print('UP')
elif a[-1] == 15:
    print('DOWN')
elif n == 1:
    print(-1)
elif a[-1] < a[-2]:
    print('DOWN')
else:
    print('UP')