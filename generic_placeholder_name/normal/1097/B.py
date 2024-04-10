#"Clearing really easy shit", episode 6
import sys
input = sys.stdin.readline

n = int(input())
x = int(input())
a = [abs(x), -abs(x)]

for i in range(n - 1):
    x = int(input())
    b = [(d + x) % 360 for d in a]
    c = [(d - x) % 360 for d in a]
    a = b + c
 
print(['NO', 'YES'][0 in a])