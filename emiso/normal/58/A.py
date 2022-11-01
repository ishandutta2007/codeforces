s = input()

hello = "hello"
pos = 0

for c in s:
    if c == hello[pos]:
        pos += 1
        if pos == 5: break

if pos == 5: print("YES")
else: print("NO")