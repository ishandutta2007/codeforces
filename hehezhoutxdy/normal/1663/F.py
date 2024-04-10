s = input().strip()
words = ["","","","the","","buffy","slayer","vampire"]
if len(s)==4:
    print("none")
else:
    target = words[len(s)]
    ans = ""
    for i in range(len(s)):
        a = ord(s[i])-ord('a')
        b = ord(target[i])-ord('a')
        ans += chr((a+b)%26 + ord('a'))
    print(ans)