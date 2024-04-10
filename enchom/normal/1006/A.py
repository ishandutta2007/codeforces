n = int(input())
nums = list( map(int, input().split()) )

def toOdd(x):
    if (x % 2 == 1):
        return x
    else:
        return x-1

print(*(map(toOdd,nums)))