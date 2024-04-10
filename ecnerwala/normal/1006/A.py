input()
print(*(x-1+x%2 for x in map(int,input().split())))