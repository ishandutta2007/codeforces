#"Clearing really easy shit", episode 8
#import sys
#input = sys.stdin.readline
#??? this runs ???

for _ in range(int(input())):
    s = input()
    a = 0
    
    for w in range(1, 20):
        z = 0
        x = int(s[:w - 1], 2) if w > 1 else 0
        for c in range(len(s) - w + 1):
            x <<= 1
            x += s[c + w - 1] == '1'
            a += s[c] == '1' and x >= w and x - w <= z
            z = z + 1 if s[c] == '0' else 0
            if s[c] == '1':
                x -= 1 << (w - 1)
                
    print(a)