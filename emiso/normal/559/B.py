a = input()
b = input()

def equivalent(l1, r1, l2, r2):
    if a[l1:r1] == b[l2:r2]: return True
    if (r1 - l1) % 2 == 1: return False

    m1 = (l1 + r1) // 2
    m2 = (l2 + r2) // 2

    if equivalent(m1, r1, l2, m2):
        if equivalent(l1, m1, m2, r2):
            return True
        else:
            return False
    else:
        if equivalent(l1, m1, l2, m2):
            if equivalent(m1, r1, m2, r2):
                return True
            else:
                return False
        else:
            return False

if equivalent(0, len(a), 0, len(b)):
    print("YES")
else:
    print("NO")