for _ in range(int(input())):
    x=int(input())
    print(2*x-bin(2*x).count('1'))