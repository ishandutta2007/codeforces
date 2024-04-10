k, d, t = gets().split().map{|x| 2*(x.to_i)}
r = (d - k%d) % d
n = k/d
n += 1 if r != 0

ans = 0
if t <= k
	ans += t
else
	cycle = k + r/2
	ans += t/cycle * n * d
	t %= cycle
	if t <= k
		ans += t
	else
		ans += k + 2*(t-k)
	end
end

puts "%.10f" % [ans/2.0]