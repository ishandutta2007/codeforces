def main():
    input()
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    ans1 = max(0, b[1] - a[1] - a[2], b[2] - a[2] - a[0], b[0] - a[0] - a[1])
    ans2 = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])
    print('{} {}'.format(ans1, ans2))

main()