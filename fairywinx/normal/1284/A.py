n, m = map(int, input().split())
a = input().split()
b = input().split()
q = int(input())
for i in range(q):
    z = int(input())
    print(a[(z - 1) % n] + b[(z - 1) % m])