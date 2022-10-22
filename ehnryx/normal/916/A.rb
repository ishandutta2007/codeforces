x = gets.to_i
h, m = gets.split().map(&:to_i)

ans = 0
while true
	if h.to_s.include? '7' or m.to_s.include? '7'
		break
	end
	m -= x
	if m < 0
		h = (h + 24-1) % 24
		m += 60
	end
	ans += 1
end
puts ans