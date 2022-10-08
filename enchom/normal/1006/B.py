n, k = map(int, input().split())
nums = list(map(int, input().split()))
indexedNums = [(nums[i], i) for i in range(len(nums))]
indexedNums.sort()
indexedNums.reverse()
indexedNums = indexedNums[:k]

indices = [indexedNums[i][1] for i in range(len(indexedNums))]

sum = 0
for i in range(len(indices)):
    sum = sum + nums[indices[i]]

indices.sort()
indices.pop()
indices.append(-1)
indices.append(n-1)
indices.sort()

gaps = [indices[i+1]-indices[i] for i in range(len(indices)-1)]

print(sum)
print(*gaps)