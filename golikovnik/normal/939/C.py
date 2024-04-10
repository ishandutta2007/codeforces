n = int(input())
a = [int(i) for i in input().split()]
s, f = map(int, input().split())
s -= 1
f -= 2
pref = [0] * n
pref[0] = a[0]
for i in range(1, n):
	pref[i] = pref[i - 1] + a[i]
mx = -1
ans = 0
for hour in range(n):
	left = s - hour
	right = f - hour
	if left < 0:
		left += n
	if right < 0:
		right += n
	res = -1
	if left <= right:
		res = pref[right] - (pref[left - 1] if left > 0 else 0)
	else:
		res = pref[n - 1] - (pref[left - 1] if left > 0 else 0) + pref[right]
	if res > mx:
		mx = res
		ans = hour + 1
print(ans)