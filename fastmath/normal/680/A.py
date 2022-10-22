a = list(map(int,input().split()))
a.sort()
arr = []
arr.append(a[0]+a[1]+a[2]+a[3]+a[4])
if a[2] == a[3] == a[4]:
    arr.append(a[0]+a[1])
if a[1] == a[2] == a[3]:
    arr.append(a[0]+a[4])
if a[0] == a[1] == a[2]:
    arr.append(a[3]+a[4])
if a[0] == a[1]:
    arr.append(a[2]+a[3]+a[4])
if a[1] == a[2]:
    arr.append(a[0]+a[3]+a[4])
if a[2] == a[3]:
    arr.append(a[0]+a[1]+a[4])
if a[3] == a[4]:
    arr.append(a[0]+a[1]+a[2])
print(min(arr))