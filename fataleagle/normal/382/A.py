left, right=raw_input().split('|')
for letter in raw_input():
    if len(left)<len(right):
        left+=letter
    else:
        right+=letter
if len(left)==len(right):
    print left+'|'+right
else:
    print "Impossible"