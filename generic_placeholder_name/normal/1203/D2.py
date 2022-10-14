#Well that didn't work
#Didn't expect it to, anyway
#Here's an actually reasonable solution

#"Clearing really easy shit", episode 5
import sys
input = sys.stdin.readline

s = input()
t = input()
 
i = 0
l = []
for c in t:
    while s[i] != c:
        i += 1
    l.append(i)
    i += 1
 
i = len(s) - 1
r = []
for c in t[::-1]:
    while s[i] != c:
        i -= 1
    r.append(i)
    i -= 1
 
r.reverse()
 
mx = r[0]
for i in range(len(t) - 1):
    mx = max(mx, r[i + 1] - l[i] - 1)
mx = max(mx, len(s) - l[-1] - 1)
 
print(mx)