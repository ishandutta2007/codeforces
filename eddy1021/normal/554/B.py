n=int(input())
s=[input() for i in range(n)]
print(max(s.count(x) for x in s))