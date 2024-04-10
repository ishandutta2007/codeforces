# VK Cup 2012 Qualification Round 1
# Problem C -- Cd and pwd commands
current = [""]
for _ in xrange(input()):
    command = raw_input()
    if command == "pwd":
        print "/".join(current) + "/"
    else:
        path = command.split()[1]
        if path[0] == "/":
            current = [""]
            path = path[1:]
        for i in path.split("/"):
            if i == "..":
                current.pop()
            else:
                current.append(i)