from sys import stdin, stdout

def main():
    n, x = map(int, stdin.readline().split())
    s = sum(map(int, stdin.readline().split()))
    if s + n - 1 == x:
        stdout.write('YES')
    else:
        stdout.write('NO')

if __name__ == '__main__':
    main()