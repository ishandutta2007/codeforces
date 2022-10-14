for _ in range(input()):
    n = input()
    m = n // 2
    if n == 1:
        print('a')
    elif n % 2 == 0: 
        print('a' * (m - 1) + 'b' + 'a' * m)
    else:
        print('a' * (m - 1) + 'bc' + 'a' * m)