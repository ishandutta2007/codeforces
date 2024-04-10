# Codeforces Alpha Round #1
# Problem A -- Jabber ID
import re
if re.match(r'^\w{1,16}\@\w{1,16}(\.\w{1,16})*(\/\w{1,16})?$', raw_input()):
    print "YES"
else:
    print "NO"