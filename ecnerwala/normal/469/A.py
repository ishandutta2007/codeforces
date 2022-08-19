a = int(input()) == len(set(map(int,input().split()[1:]+input().split()[1:])))
print("I become the guy." if a else "Oh, my keyboard!")