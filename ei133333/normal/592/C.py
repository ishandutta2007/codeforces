import math


T, W, B = map(int, input().split())

space = min(W, B)
arong = W // math.gcd(W, B) * B
add = 0
add += (T // arong) * space;
add += min(space, T % arong + 1)
add -= 1

if add == 0:
    print("0/1")
else:
  v = math.gcd(T, add);
  T //= v;
  add //= v;
  print(add,"/",T, sep='')