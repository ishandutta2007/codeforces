s = input()
k = int(input())
parsed = []
i = 0
while i < len(s):
    c = s[i]
    op = ''
    if i + 1 < len(s):
        cnext = s[i + 1]
        if cnext in {'?', '*'}:
            op = cnext
            i = i + 1
    parsed.append((c, op))
    i = i + 1

min_l = sum(1 for _, op in parsed if op == '')
max_l = 201 if any(op == '*' for _, op in parsed) else len(parsed)
if min_l <= k <= max_l:
    num_quest = sum(1 for _, op in parsed if op == '?')
    quests_to_use = min(num_quest, k - min_l)
    star_nums = k - quests_to_use - min_l
    for c, op in parsed:
        if op == '':
            print(c, end='')
        elif op == '?':
            if quests_to_use > 0:
                print(c, end='')
                quests_to_use -= 1
        else:
            if star_nums:
                print(c * star_nums, end='')
                star_nums = 0
    print()
else:
    print('Impossible')