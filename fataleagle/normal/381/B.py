n=input()
nums=map(int, raw_input().split())
nums.sort()
use=[]
left=[]
for i in nums:
    if not use or i>use[-1]:
        use.append(i)
    else:
        left.append(i)
for i in reversed(left):
    if i<use[-1]:
        use.append(i)
print len(use)
print " ".join(map(str, use))