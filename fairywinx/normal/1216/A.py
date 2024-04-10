n = int(input())
a = list(input())
l1, l2 = 0, 0
m = ''
ans = 0
for i in range(1, n, 2):
    m = a[i - 1:i + 1]
    if m == ['a', 'a']:
        a[i] = 'b'
        ans += 1
    if m == ['b', 'b']:
        a[i] = 'a'
        ans += 1
print(ans)
print(*a, sep ='')