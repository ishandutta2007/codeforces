if __name__=="__main__":
    n, m = [int(i) for i in input().split(' ')]
    A = [int(i) for i in input().split(' ')]
    B = [int(i) for i in input().split(' ')]
    a = [0, 0]
    b = [0, 0]
    for i in A:
        a[i & 1] += 1
    for i in B:
        b[i & 1] += 1
    print(min(a[0], b[1]) + min(a[1], b[0]))