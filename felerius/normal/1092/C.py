n = int(input())
strings = [input() for _ in range(2*n - 2)]

l1, l2 = (s for s in strings if len(s) == n - 1)

def f(a, b, strings):
    if a[1:] != b[:-1]:
        return
    full = a + b[-1]
    prev = [None] * (n)
    result = [None] * len(strings)
    for i, s in enumerate(strings):
        is_prefix = s == full[:len(s)]
        is_suffix = s == full[-len(s):]
        if is_prefix:
            if is_suffix:
                if prev[len(s)] is None:
                    result[i] = 'P'
                    prev[len(s)] = 'P'
                elif prev[len(s)] == 'P':
                    result[i] = 'S'
                else:
                    result[i] = 'P'
            else:
                result[i] = 'P'
                prev[len(s)] = 'P'
        else:
            if is_suffix:
                result[i] = 'S'
                prev[len(s)] = 'S'
            else:
                return
    return result

for (a, b) in [(l1, l2), (l2, l1)]:
    result = f(a, b, strings)
    if result is not None:
        print(''.join(result))
        break