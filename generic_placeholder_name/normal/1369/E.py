import sys
input = sys.stdin.readline

def line_input():
    return [int(x) for x in input().split()]

def main():
    n, m = line_input()
    w = line_input()
    adj = [[] for _ in range(n)]
    edges = []
    deg = [0] * n
    for i in range(m):
        u, v = line_input()
        u, v = u - 1, v - 1
        adj[u].append(v)
        adj[v].append(u)
        edges.append((u, v))
        deg[u] += 1
        deg[v] += 1
    vis = [False] * n
    order = [0] * n
    st = []
    cur = 0
    for i in range(n):
        if deg[i] <= w[i]:
            vis[i] = True
            order[i] = cur
            cur += 1
            st.append(i)
    while len(st):
        u = st.pop()
        for v in adj[u]:
            deg[v] -= 1
            if not vis[v] and deg[v] <= w[v]:
                vis[v] = True
                order[v] = cur
                cur += 1
                st.append(v)
    if sum(vis) < n:
        print('DEAD')
    else:
        print('ALIVE')
        edge_order = [sorted([order[edges[i][0]], order[edges[i][1]]]) for i in range(m)]
        idx = [x for x in range(m)]
        print(*[x+1 for x in sorted(idx, key=lambda x: edge_order[x], reverse=True)])
    
main()