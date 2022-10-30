import random
S=raw_input()
ans=eval(S)
S+='*1'
for i in xrange(1, len(S), 2):
    if S[i]=='*':
        t=S[i:]
        u=S[i+2:]
        for j in xrange(0, i, 2):
            if j==0 or j==len(S)-1 or S[j-1]=='*':
                w="".join((S[:j], "(", S[j:i]))
                # .. (X ... Y) * ...
                ans=max(ans, eval("".join((w, ")", t))))
                # ... (X ... * Y) ...
                ans=max(ans, eval("".join((w, S[i:i+2], ")", u))))
print ans