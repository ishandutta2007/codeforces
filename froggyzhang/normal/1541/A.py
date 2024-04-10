for T in range(int(input())):
    n = int(input())
    if n % 2 == 0:
        for i in range(1,n,2):
            print(i+1,i)
    else:
        print(3,1,2)
        for i in range(4,n,2):
            print(i+1,i)