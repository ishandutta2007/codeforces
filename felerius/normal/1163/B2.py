n = int(input())
u = map(int, input().split())
max_x = 1
counts = [0] * 10**5
first_u = next(u)
counts[first_u - 1] = 1
count_counts = {1: 1}

for i, v in enumerate(u):
    v -= 1
    counts[v] += 1
    if counts[v] > 1:
        count_counts[counts[v] - 1] -= 1
        if count_counts[counts[v] - 1] == 0:
            del count_counts[counts[v] - 1]
    if counts[v] in count_counts:
        count_counts[counts[v]] += 1
    else:
        count_counts[counts[v]] = 1
    if len(count_counts) == 2:
        a, b = sorted(count_counts.keys())
        if (b == a + 1 and count_counts[b] == 1) or (a == 1 and count_counts[a] == 1):
            max_x = i + 2
    elif len(count_counts) == 1:
        a = next(iter(count_counts.keys()))
        if a == 1 or count_counts[a] == 1:
            max_x = i + 2

print(max_x)

# counts = [0] * 10
# max_x = 1
# for i, v in enumerate(u):
#     v -= 1
#     counts[v] += 1
#     as_set = set(counts)
#     if 0 in as_set:
#         as_set.remove(0)
#     if len(as_set) == 1:
#         if next(iter(as_set)) == 1:
#             max_x = i + 1
#     elif len(as_set) == 2:
#         a, b = sorted(as_set)
#         if a == 1:
#             if sum(1 for c in counts if c == 1) == 1:
#                 max_x = i + 1
#         if b == a + 1:
#             if sum(1 for c in counts if c == b) == 1:
#                 max_x = i + 1
#
# print(max_x)