n = int(input())
a = [*map(int,input().split())]
sa = sum(a)
ma = max(a)
print("YNEOS"[(sa % 2 or ma > sa - ma)::2])