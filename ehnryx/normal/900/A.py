#!/usr/env
from math import *
from sets import *
from collections import *
from sys import *
from re import *
from os import *

# advent of code
from hashlib import *
#

pos = neg = 0

n = int(raw_input())
for i in range(0, n):
	x,y = map(int, raw_input().split())
	if x > 0:
		pos += 1
	else:
		neg += 1

if pos <= 1 or neg <= 1:
	print "Yes"
else:
	print "No"