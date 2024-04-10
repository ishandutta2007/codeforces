def ask(t, i, j):
    print(t, i + 1, j + 1)
    return int(input())
    
def main():
    n = int(input())
    a = [0] * n
    x = [0] * n
    p = [-1] * n
    p[0] = 0
    for i in range(1, n):
        x[i] = ask('XOR', 0, i)
    for i in range(1, n):
        if p[x[i]] != -1:
            a[i] = ask('AND', i, p[x[i]])
            a[0] = a[i] ^ x[i]
            for j in range(1, n):
                a[j] = a[0] ^ x[j]
            print('!', *a)
            return
        else:
            p[x[i]] = i
    id1 = p[n - 1]
    id2 = 1 if id1 != 1 else 2
    s1 = n - 1
    s2 = x[id2] + 2 * ask('AND', 0, id2)
    s12 = (x[id1] ^ x[id2]) + 2 * ask('AND', id1, id2)
    a[0] = (s1 + s2 - s12) // 2
    for i in range(1, n):
        a[i] = a[0] ^ x[i]
    print('!', *a)
    
main()