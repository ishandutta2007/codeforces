s = raw_input()

def palindrome(l, r):
    str =  s[l:r+1]
    return str == str[::-1]

best = 0
for l in xrange(1, len(s) + 1):
    for i in xrange(0, len(s) - l + 1):
        if(not palindrome(i, i + l - 1)):
            best = l

print best