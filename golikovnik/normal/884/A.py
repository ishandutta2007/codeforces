from sys import stdin, stdout

def main():
    sec_day = 86400
    n, t = map(int, stdin.readline().split())
    cnt = 0
    for cur in stdin.readline().split():
        cur = int(cur)
        t -= sec_day - cur
        cnt += 1
        if t <= 0:
            stdout.write(str(cnt))
            break

if __name__ == '__main__':
    main()