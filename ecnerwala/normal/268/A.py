a=[raw_input().split()for _ in range(input())]
print sum(x[0]==y[1]for x in a for y in a)