def ask(t, i, j):
    print(t, i + 1, j + 1)
    return int(input())
    
def main():
    n = int(input())
    a = [0] * n
    xr01 = ask('XOR', 0, 1)
    xr12 = ask('XOR', 1, 2)
    xr02 = xr01 ^ xr12
    nd01 = ask('AND', 0, 1)
    nd02 = ask('AND', 0, 2)
    nd12 = ask('AND', 1, 2)
    s01 = xr01 + 2 * nd01
    s02 = xr02 + 2 * nd02
    s12 = xr12 + 2 * nd12
    a[0] = (s01 + s02 - s12) // 2
    a[1] = (s01 + s12 - s02) // 2
    a[2] = (s02 + s12 - s01) // 2
    for i in range(3, n):
        a[i] = a[0] ^ ask('XOR', 0, i)
    print('!', *a)
    
main()