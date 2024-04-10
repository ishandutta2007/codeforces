input()
def v(x):
    ret = 0
    for i in x:
        if ord('A') <= ord(i) <= ord('Z'):
            ret += 1
    return ret
print(max(v(i) for i in input().strip().split()))