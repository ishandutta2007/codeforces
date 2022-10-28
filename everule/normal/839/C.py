from sys import stdin, setrecursionlimit
from collections import *
import threading


class graph:
    # initialize graph
    def __init__(self, gdict=None):
        if gdict is None:
            gdict = defaultdict(list)
        self.gdict, self.edges, self.l = gdict, [], defaultdict(int)

    # add edge
    def addEdge(self, node1, node2, w=None):
        self.gdict[node1].append(node2)
        self.gdict[node2].append(node1)
        self.l[node1] += 1
        self.l[node2] += 1

    def bfs(self, i):
        self.visit, ans = [0] * (n + 1), []
        queue, self.visit[i] = deque([[i, 0]]), 1

        while queue:
            # dequeue parent vertix
            s, dist = queue.popleft()

            # enqueue child vertices
            for i in self.gdict[s]:
                if self.visit[i] == 0:
                    queue.append([i, dist + 1])
                    self.visit[i] = 1

            if self.l[s] == 1 and s != 1:
                ans.append(dist)

        return 0 if not ans else (n - 1) / len(ans)

    def DfsUtil(self, v):

        self.visit[v], val = 1, [0, 0]

        for i in self.gdict[v]:
            if self.visit[i] == 0:
                val[0] += self.DfsUtil(i)
                val[1] += 1

        if self.l[v] == 1 and v != 1:
            return 0.0
        else:
            return (val[0] / val[1]) + 1.0

    def dfs(self, n):
        self.visit = [0] * (n + 1)
        return self.DfsUtil(1)


def main():
    n, g = int(stdin.readline()), graph()

    for i in range(n - 1):
        u, v = map(int, stdin.readline().split())
        g.addEdge(u, v)

    print('{:.10f}'.format(g.dfs(n)) if n > 1 else '{:.10f}'.format(0))


if __name__ == '__main__':
    setrecursionlimit(10**9)
    threading.stack_size(2**27)
    thread = threading.Thread(target=main)
    thread.start()