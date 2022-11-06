input()
nums = set(map(int, input().split()))
if len(nums) == 1:
    print(0)
elif len(nums) == 2:
    a, b = nums
    if abs(a - b) % 2 == 0:
        print(abs(a - b) // 2)
    else:
        print(abs(a - b))
elif len(nums) == 3:
    a, b, c = sorted(nums)
    if (b - a == c - b):
        print(b - a)
    else:
        print(-1)
else:
    print(-1)