# MAGIC CODEFORCES PYTHON FAST IO
import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
# END OF MAGIC CODEFORCES PYTHON FAST IO

def tPrimos():
    TOPE_CRIBA = 1000000
    cribaArray = [True] * TOPE_CRIBA
    cribaArray[0] = cribaArray[1] = False
    for p in range(TOPE_CRIBA):
        if cribaArray[p]:
            for j in range(p*p, TOPE_CRIBA, p):
                cribaArray[j] = False
    return set(p*p for p in range(TOPE_CRIBA) if cribaArray[p])

def solve():
    yesSet = tPrimos()
    n = int(input())
    for number in map(int, input().split()):
        if number in yesSet:
            print("YES")
        else:
            print("NO")

solve()