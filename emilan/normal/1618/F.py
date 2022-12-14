#!/usr/bin/env python3

from collections import deque
import functools
import itertools
import math

def main():
    s, t = [f"{int(x):b}" for x in input().split()]

    vis = {s}
    q = deque([s])
    while q:
        x = q.pop()

        y = x[::-1].lstrip("0")
        z = (x + "1")[::-1].lstrip("0")
        for i in [y, z]:
            # No actually 60 should be fine
            if len(i) <= 60 and i not in vis:
                vis.add(i)
                q.append(i)
    if t in vis: print("YES")
    else: print("NO")

if __name__ == "__main__": main()