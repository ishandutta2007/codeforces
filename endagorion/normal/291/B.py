s = raw_input() + " "
ans = []        
cs = ""
inside = False
for c in s:
    if c == "\"":
        if inside:
            ans.append(cs)
        cs = ""
        inside = not inside
    elif c == " ":
        if inside:
            cs += c
        else:
            if cs != "":
                ans.append(cs)
                cs = ""
    else:
        cs += c
for ss in ans:
    print "<" + ss + ">"