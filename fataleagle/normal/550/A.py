S=raw_input()
if "AB" not in S or "BA" not in S:
    print "NO"
else:
    a=S.find("AB")
    b=S.find("BA")
    c=S.rfind("AB")
    d=S.rfind("BA")
    if a+1<d or b+1<c:
        print "YES"
    else:
        print "NO"