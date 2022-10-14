# Codeforces Beta Round #14
# Problem B -- Young Photographer
n, x0 = map(int, raw_input().split());
st, ed = 0, 1000;
for i in range(n):
    ai, bi = map(int, raw_input().split());
    if ai > bi:
        ai, bi = bi, ai;
    st, ed = max(st, ai), min(ed, bi);
if st > ed:
    print -1;
elif (st <= x0) and (x0 <= ed):
    print 0;
else:
    print min(abs(x0 - st), abs(x0 - ed));