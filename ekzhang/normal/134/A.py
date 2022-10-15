N = int(input())
ar = [int(x) for x in input().split()]
ans = []
s = sum(ar)
for i, j in enumerate(ar):
    if j * N == s:
        ans.append(str(i + 1))

print(len(ans))
print(' '.join(ans))