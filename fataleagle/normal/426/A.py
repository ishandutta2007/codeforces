a, b=map(int, raw_input().split())
print "YES" if sum(sorted(map(int, raw_input().split()))[:-1])<=b else "NO"