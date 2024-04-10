A=raw_input()
B=raw_input()
yellow=set()
red=set()
for _ in xrange(input()):
    a, b, c, d=raw_input().split()
    if d=='y':
        if (b, c) in yellow:
            if (b, c) not in red:
                print (A if b=='h' else B), c, a
                red.add((b, c))
        yellow.add((b, c))
    elif (b, c) not in red:
        print (A if b=='h' else B), c, a
        red.add((b, c))