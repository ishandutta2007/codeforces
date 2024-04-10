def expand(s):
    while len(s) < 4:
        s = '0' + s
    return s

for i in xrange(input()):
    s = raw_input().split(':')
    answer = ["0000"] * 8
    for k, v in enumerate(s):
        if not v:
            break
        answer[k] = expand(v)
    for k, v in enumerate(reversed(s)):
        if not v:
            break
        answer[7 - k] = expand(v)
    print ":".join(answer)