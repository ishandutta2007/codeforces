n = ['no', 'great', "dontthinkso", "donttouchme", "notbad", "cool", "no", "no", "no", "no"]
g = ["no", "donteven", "areyouserious", "godieinahole", "worse", "terrible", "noway", "noway", "no", "no"]
for i in range(10):
  print(i, flush=True)
  v = "".join(c for c in input().lower() if 'a' <= c <= 'z')
  if v in n and v in g:
     n.remove(v)
     g.remove(v)
     continue
  print("grumpy" if v in g else "normal")
  break