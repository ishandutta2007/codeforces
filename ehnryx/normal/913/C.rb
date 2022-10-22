#!/usr/bin/ruby
include Math

INF = 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f

n, v = gets.split().map(&:to_i)
cost = gets.split().map(&:to_i)

best = []
best[0] = INF
res = INF
for i in 1..n
	best[i] = [2*best[i-1], cost[i-1]].min
	if 2**(i-1) >= v
		res = [res, best[i]].min
	end
end
for i in n+1..70
	best[i] = 2*best[i-1]
	if 2**(i-1) >= v
		res = [res, best[i]].min
	end
end

ans = INF
vv = v
while (vv & -vv) != vv
	temp = 0
	j = 0
	v = vv
	while v > 0
		j += 1
		if v % 2 == 1
			temp += best[j]
		end
		v /= 2
	end
	ans = [ans, temp].min
	vv += vv & -vv
end

puts [res, ans].min