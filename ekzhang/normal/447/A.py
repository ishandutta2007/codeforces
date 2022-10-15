def getAns(p, nums):
    hashes = []
    for i in xrange(len(nums)):
        h = nums[i] % p
        if h in hashes:
            return i + 1
        else:
            hashes.append(h)
    return -1

P, N = map(int, raw_input().split())
nums = [input() for _ in xrange(N)]
print getAns(P, nums)