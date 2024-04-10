n = int(input())
a = [input() for _ in range(n)]
a.sort(key=len)
if all(a[i] in a[i+1] for i in range(n-1)):
    print("YES")
    print(*a, sep='\n')
else:
    print("NO")