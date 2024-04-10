from sys import stdin
stdin.readline()
for s in stdin:
    print(s[::2].replace("\n", s[-2]))