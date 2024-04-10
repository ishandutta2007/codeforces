s = input()
n = len(s)
if n < 7:
  print("NO")
  exit(0)
subs = [s[i:i+7] for i in range(n - 6)]
print("YES" if "1" * 7 in subs or "0" * 7 in subs else "NO")