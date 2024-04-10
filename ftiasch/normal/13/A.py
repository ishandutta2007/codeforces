# Codeforces Beta Round #13
# Problem A -- Numbers
a, s = int(input()), 0;
for b in range(2, a):
    c = a;
    while c:
        s += c % b;
        c /= b;
x, y = s, a - 2;
while y:
    x, y = y, x % y;
print "%d/%d" %(s / x, (a - 2) / x);