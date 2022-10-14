def check(a, b):
    return not a or not b or abs(ord(a[-1]) - ord(b[0])) > 1

for _ in range(int(input())):
    s = input()
    odds = list(sorted(filter(lambda c: (ord(c) - ord('a')) % 2 == 1, s)))
    evens = list(sorted(filter(lambda c: (ord(c) - ord('a')) % 2 == 0, s)))
    if check(odds, evens):
        print(''.join(odds + evens))
    elif check(evens, odds):
        print(''.join(evens + odds))
    else:
        print('No answer')