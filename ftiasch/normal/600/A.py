tokens = input().replace(";", ",").split(",")
result = [[], []]
for token in tokens:
    result[not token.isdigit() or str(int(token)) != token].append(token)
for s in result:
    print('"' + ",".join(s) + '"' if s else "-")