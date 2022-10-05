s = "aeiou13579"
h = input()
ans = 0
for c in h:
    if c in s:
        ans += 1
print(ans)