from math import floor
def work(l):
    global len
    global n
    if l == 0:
        return int(n)
    a = ""
    b = ""
    a = n[0:l]
    b = n[l:len]
    lena = l
    lenb = len - l
    lb = 0
    while (lb < lenb - 1 and b[lb] == '0'):
        lb += 1;
    if (b[lb] == '0'):
        ans = int(n)
    else:
        ans = int(a + b[0:lb]) + int(b[lb:lenb])
    la = lena - 1
    while (lena and a[la] == '0'):
        la -= 1;
    if la:
        ans = min(ans, int(a[0:la]) + int(a[la:lena] + b))
    return ans
len = int(input())
n = input()
print(min(min(work(floor(len / 2)), work(floor((len + 1) / 2))), work(floor((len - 1) / 2))))