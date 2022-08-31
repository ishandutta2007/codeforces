def f(n):
    if n == 3:
        return [[1, 2, 3], [1, 2, 3]]
    elif n % 2 == 1:
        a = f(n - 2)
        for i in xrange(1, n - 2, 2):
            a.append([i, n, i + 1, n - 1])
            a.append([i, n, i + 1, n - 1])
        a.append([n, n - 1, n - 2])
        a.append([n, n - 1, n - 2])
        return a
    else:
        a = f(n - 1)[::2]
        for v in a:
            for i in xrange(len(v)):
                if v[i] == n - 1:
                    v[i] += 1
        a.extend(f(n - 1)[::2])
        for i in xrange(1, n - 3, 2):
            a.append([i, n, i + 1, n - 1])
        a.append([n, n - 1, n - 2])
        a.append([n, n - 1, n - 3])
        return a

n = int(raw_input())

a = f(n)
print len(a)
for v in a:
    print len(v), " ".join(map(str, v))