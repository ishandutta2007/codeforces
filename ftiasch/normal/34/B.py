# Codeforces Beta Round #34
# Problem B -- Sale
n, m = map(int, raw_input().split())
a = map(int, raw_input().split())
s = 0
for i in sorted(a)[:m]:
	s -= min(i, 0)
print s