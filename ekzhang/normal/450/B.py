from __future__ import division

X, Y = map(int, raw_input().split())
N = input()

"""# inaccurate (python bad) find general form then plug in way
C1 = complex(0.5, (3 ** (1 / 2)) / 2)
C2 = complex(0.5, -(3 ** (1 / 2)) / 2)
D = complex(0, (3 ** (1 / 2)))
A = (X + (Y - X) * C2) / D
B = (C1 * (X - Y) - X) / D

ans = (A * (C1 ** N) + B * (C2 ** N)).real % 1000000007
print int(ans)
"""

# accurate bash way taking advantage of n cycle by 6
def bash(x, y, n):
    return [x, y, y-x, -x, -y, -y+x][n - 1]

print bash(X, Y, N % 6) % 1000000007