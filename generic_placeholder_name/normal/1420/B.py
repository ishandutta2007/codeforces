def main():
    for _ in range(int(input())):
        n = int(input())
        a = [int(x) for x in input().split()]
        cnt = [0] * 30
        for i in range(n):
            cur, tmp = 1, 1
            while cur <= a[i]:
                cur *= 2
                tmp += 1
            cnt[tmp-2] += 1
        print(sum([x * (x-1) // 2 for x in cnt]))

main()