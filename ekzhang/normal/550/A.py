s = input()
ans = False
find1 = s.find('AB')
find2 = s.find('BA')
if find1 != -1:
    if s.find('BA', find1 + 2) != -1:
        ans = True
if find2 != -1:
    if s.find('AB', find2 + 2) != -1:
        ans = True

if ans:
    print('YES')
else:
    print('NO')

import sys
sys.exit(0);