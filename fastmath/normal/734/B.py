a2, a3, a5, a6 = map(int, input().split())
ans = 256 * min(a2, a5, a6)
a2 -= min(a2, a5, a6)
print(ans + 32 * min(a2, a3))