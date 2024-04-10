t = int(input())
for i in range(t):
    l = int(input())
    s = input()

    if s[0] == '9':
        print(int('1'*(l+1))-int(s))
    else:
        print(int('9'*l)-int(s))