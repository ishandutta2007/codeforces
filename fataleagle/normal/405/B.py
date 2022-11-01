N=input()
state=raw_input()
left=[]
right=[]
for i in xrange(len(state)):
    if state[i]=='L': left.append(i)
    elif state[i]=='R': right.append(i)
if not left and not right:
    print N
elif not left:
    print right[0]
elif not right:
    print N-left[0]-1
else:
    ans=0
    leftfirst=left[0]<right[0]
    if leftfirst:
        for i in xrange(len(left)-1):
            ans+=int((left[i+1]-right[i])%2==0)
            ans+=right[i]-left[i]-1
        if left[-1]>right[-1]:
            ans+=N-left[-1]-1
        else:
            ans+=right[-1]-left[-1]-1
    else:
        N+=1
        left.insert(0, -1)
        for i in xrange(len(left)):
            left[i]+=1
        for i in xrange(len(right)):
            right[i]+=1
        for i in xrange(len(left)-1):
            ans+=int((left[i+1]-right[i])%2==0)
            ans+=right[i]-left[i]-1
        if left[-1]>right[-1]:
            ans+=N-left[-1]-1
        else:
            ans+=right[-1]-left[-1]-1
    print ans