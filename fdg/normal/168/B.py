__author__ = 'Fdg'
import sys

line=""
ok=0
for s in sys.stdin:
    ns=s.strip()
    if len(ns)>0 and ns[0]=='#':
        if ok: print(line)
        print(s[0:len(s)-1])
        ok=0
        line=""
    else:
        s=s.replace(' ','')
        if len(s)>0: ok=1
        line+=s[0:len(s)-1]
if ok: print(line)