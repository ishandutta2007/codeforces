h, w = map(int, input().split())
for i in range(h):
    if i % 2 == 0:
        print('#' * w)
    elif i % 4 == 1:
        print('.' * (w - 1) + '#')
    else:
        print('#' + '.' * (w - 1))