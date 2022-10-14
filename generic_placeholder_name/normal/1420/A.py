def get(a):
    if len(list(set(a))) != len(a):
        return 1
    if list(reversed(sorted(a))) != a:
        return 1
    return 0

def main():
    for _ in range(int(input())):
        n = int(input())
        a = [int(x) for x in input().split()]
        print(['NO', 'YES'][get(a)])
        
main()