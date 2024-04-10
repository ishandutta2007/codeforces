from sys import stdin, stdout

n = int(stdin.readline())

for nn in range(n):
    a, b, m = map(int,stdin.readline().split())
    if a == b:
        stdout.write('{} {}\n'.format(1,a))
    else:
        for j in range(2,51):
            if (a+1)<<(j-2) <= b and b <= (a+m)<<(j-2):
                B = b
                b -= a<<(j-2)
                stdout.write('{} {}'.format(j, a))
                s = a
                for i in range(j-2):
                    left = 1
                    right = m
                    while left < right:
                        k = (left+right+1)//2
                        if b - (k<<(j-3-i)) >= 1<<(j-3-i):
                            left = k
                        else:
                            right = k-1
                    a = s+left
                    stdout.write(' {}'.format(a))
                    s += a
                    b -= left<<(j-3-i)
                stdout.write(' {}\n'.format(B))
                break
        else:
            stdout.write('-1\n')