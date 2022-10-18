def H(dx):
  if dx < 10:
    return dx * (dx + 1) / 2

  p10 = 1
  while p10 * 10 <= dx:
    p10 *= 10

  d = dx / p10
  x = dx % p10

  return d * (x + 1) + d * (d - 1) / 2 * p10 + (d + 1) * H(p10 - 1)


p10 = 10 ** 19
mod = int(raw_input())
s9 = H(p10 - 1) % mod
x = mod - s9 - 1

print x + 1, p10 + x