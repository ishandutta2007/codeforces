dis = [1000000] * 30000
n, m = map(int, raw_input().split())
q = [n]
dis[n] = 0
while len(q) > 0:
	t = q[0]
	q = q[1:]
	if t < m and dis[t*2] > dis[t] + 1:
		dis[t*2] = dis[t] + 1
		q.append(t*2)
	if t > 1 and dis[t-1] > dis[t] + 1:
		dis[t-1] = dis[t] + 1
		q.append(t-1)
print dis[m]