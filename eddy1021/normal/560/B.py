def ok(x1, y1, x2, y2, x3, y3):
  if max(x2,x3) <= x1 and y2 + y3 <= y1: return True
  if max(y2,y3) <= y1 and x2 + x3 <= x1: return True
  return False
def okay(x1, y1, x2, y2, x3, y3):
  if ok(x1, y1, x2, y2, x3, y3): return True
  if ok(x1, y1, x2, y2, y3, x3): return True
  if ok(x1, y1, y2, x2, x3, y3): return True
  if ok(x1, y1, y2, x2, y3, x3): return True
  return False
a1, b1 = list(map(int,input().split()))
a2, b2 = list(map(int,input().split()))
a3, b3 = list(map(int,input().split()))
print("YES" if okay(a1, b1, a2, b2, a3, b3) else "NO")