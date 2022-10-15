import functools
import sys
import threading
sys.setrecursionlimit(100013)

@functools.lru_cache(maxsize=None)
def go(n):
    return 1 + max((go(n - k) for k in nums if n >= k), default=float('-inf')) if n else 0

nums = [int(x) for x in input().split()]
def main():
    print(go(nums.pop(0)))

if __name__ == '__main__':
    threading.stack_size(20000000)
    threading.Thread(target=main).start()