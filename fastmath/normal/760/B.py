def just_sum(n):
    return (n * (n + 1)) // 2


def get_sum(a, b):
    return just_sum(b) - just_sum(a - 1)


def check(middle):
    left = k - 1
    right = n - k
    
    if left < middle:
        left_sum = get_sum(middle - left, middle - 1)
    else:
        left_sum = just_sum(middle - 1) + (left - (middle - 1))
    
    if right < middle:
        right_sum = get_sum(middle - right, middle - 1)
    else:
        right_sum = just_sum(middle - 1) + (right - (middle - 1))
    
    return left_sum + right_sum + middle <= m
    
    
n, m, k = map(int, input().split())

l = 1
r = m + 1
while l < r - 1:
    middle = (l + r) // 2
    if check(middle):
        l = middle
    else:
        r = middle
        
print(l)