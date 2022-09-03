import math
l = int(input())
num = input()
if l % 2 == 0:
    mid = l//2
    i =0
    while True:
        r = mid+i
        l = mid-i
        ans = []
        if num[r] != "0":
            ans.append(int(num[:r])+int(num[r:]))
        if num[l] != "0":
            ans.append(int(num[:l])+int(num[l:]))
        if len(ans) != 0:
            if len(ans) == 1:
                print(ans[0])
            else:
                print(min(ans[0],ans[1])) 
            break
        i=i+1
else:
    mid = l//2
    i =0
    while True:
        r = mid+i+1
        l = mid-i
        ans = []
        if num[r] != "0":
            ans.append(int(num[:r])+int(num[r:]))
        if num[l] != "0":
            ans.append(int(num[:l])+int(num[l:]))
        if len(ans) != 0:
            if len(ans) == 1:
                print(ans[0])
            else:
                print(min(ans[0],ans[1])) 
            break
        i = i+1