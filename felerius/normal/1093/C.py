input()
b = [int(s) for s in input().split(' ')]

front = [0]
back = [b[0]]
for bi in b[1:]:
    a = max(front[-1], bi - back[-1])
    front.append(a)
    back.append(bi - a)

print(' '.join(str(i) for i in (front + list(reversed(back)))))