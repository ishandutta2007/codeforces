input()
s = input()
red = blue = 0
result = ""
for c in s:
    if c == '(':
        if red > blue:
            result += '0'
            blue += 1
        else:
            result += '1'
            red += 1
    else:
        if red > blue:
            result += '1'
            red -= 1
        else:
            result += '0'
            blue -= 1

print(result)