N = input()

def main(n=N):
    if n < 4:
        print 'NO'
        return
    print 'YES'

    while True:
        if n == 5:
            print '''5 * 4 = 20
20 + 3 = 23
23 + 2 = 25
25 - 1 = 24'''
            return
        if n == 4:
            print '''1 * 2 = 2
2 * 3 = 6
6 * 4 = 24'''
            return
    
        # n > 5
        print '''{0} - {1} = 1
1 * 1 = 1'''.format(n, n - 1)
        n -= 2

if __name__ == '__main__':
    main()