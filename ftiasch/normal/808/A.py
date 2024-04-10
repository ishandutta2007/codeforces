s = input()
print(int(str(int(s[0]) + 1) + '0' * (len(s) - 1)) - int(s))