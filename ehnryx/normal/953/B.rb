n = readline().to_i
a = readline().split().map(&:to_i).sort

g = 0
left = right = a[0]
for i in 1..n-1
	g = g.gcd(a[i]-a[i-1])
	left = [a[i], left].min
	right = [a[i], right].max
end

puts (right-left)/g + 1 - n