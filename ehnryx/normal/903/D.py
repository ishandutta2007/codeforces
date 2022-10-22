#!/usr/env
from math import *
from decimal import *
from sets import *
from collections import *
from sys import *
from re import *
from os import *

# advent of code
from hashlib import *
#

count = defaultdict(int)
ans = 0
pref = 0

n = int(raw_input())
i = 0
for a in map(int, raw_input().split()):
	ans += i*a - pref
	ans -= count[a-1]
	ans += count[a+1]
	count[a] += 1
	pref += a
	i += 1

print ans