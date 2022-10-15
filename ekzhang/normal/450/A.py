class Child(object):
    def __init__(self, place, candies):
        self.place = place
        self.candies = candies

    def giveCandies(self, x):
        self.candies -= x

    def enoughCandies(self):
        return self.candies <= 0

N, M = [int(i) for i in raw_input().split()]
C = [int(i) for i in raw_input().split()]

children = []
for i, j in enumerate(C):
    children.append(Child(i + 1, j))

while len(children) > 1:
    curr = children.pop(0)
    curr.giveCandies(M)
    if not curr.enoughCandies():
        children.append(curr)

print children[0].place