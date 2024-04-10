for _ in range(int(input())):
    s = input()
    st = []
    par = 0
    for i in range(len(s)):
        if len(st) and s[i] != st[len(st) - 1]:
            st.pop()
            par ^= 1
        else:
            st.append(s[i])
    print(['NET', 'DA'][par])