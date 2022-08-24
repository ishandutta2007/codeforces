n = input()
s = input()
if s.count("1") == s.count("0"):
    print(2)
    print(s[0], s[1:])
else:
    print(1)
    print(s)