R, H = map(int, raw_input().split())
Q = (2 * H + R) / (2 * R)
L = 3 * R * R <= 4 * (H + R - Q * R) ** 2
print 2 * Q + L