import sys
input = sys.stdin.readline

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    
    a = a[0::2] + a[1::2] + a[0::2] + a[1::2]
    k = (n + 1) // 2
    
    s = sum(a[:k])
    ans = s
    for i in range(k, len(a)):
        s -= a[i - k]
        s += a[i]
        ans = max(ans, s)
        
    print(ans)
    
main()