input()
s = input()
count = 0
for i, c in enumerate(s):
    if int(c) % 2 == 0:
        count += (i + 1)
print(count)