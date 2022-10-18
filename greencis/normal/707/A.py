n, m = map(int, input().split())
bw = True
while n > 0 and bw:
    n -= 1
    s = input().split()
    for i in range(m):
        if s[i] != 'W' and s[i] != 'G' and s[i] != 'B':
            bw = False
            break
if bw:
    print("#Black&White")
else:
    print("#Color")