# your code here
n, m = [int(x) for x in input().split()]
a = [input() for _ in range(n)]

while all(row[0] == '.' for row in a):
    a = [row[1:] for row in a]

while all(row[-1] == '.' for row in a):
    a = [row[:-1] for row in a]

while not a[0].strip('.'):
    a = a[1:]

while not a[-1].strip('.'):
    a = a[:-1]

print('\n'.join(a))