# import os, sys, logging
# logging.basicConfig(format="[%(relativeCreated)dms]: %(message)s", level=logging.DEBUG)
# def debug(*args, sep=" "):
#     logging.getLogger(__name__).debug(sep.join(map(repr, args)), stacklevel=2)
# if os.environ.get("USERNAME") == "Ethan":
#     sys.stdin = open("../../input.in")
# else:
#     debug = lambda *args, **kwargs: None

# end template

for _ in range(int(input())):
    s = input()
    # debug(s)
    c = min(s)
    i = s.find(c)
    print(c, s[:i]+s[i+1:])