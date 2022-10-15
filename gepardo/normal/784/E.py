a1 = int(input())
a2 = int(input())
a3 = int(input())
a4 = int(input())

g = a1 ^ a4
f = a2 & a3
e = a3 | a4
d = a1 ^ a2
c = f | g
b = d & e
a = b ^ c

print(a)