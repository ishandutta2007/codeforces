n = int(input())

ans = 0
for i in range(n):
    s = input()
    if s == 'Tetrahedron':
        ans += 4
    elif s == 'Cube':
        ans += 6
    elif s == 'Octahedron':
        ans += 8
    elif s == 'Dodecahedron':
        ans += 12
    else:
        ans += 20
        
print(ans)