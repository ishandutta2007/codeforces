n = gets().to_i

ans = 0
for i in 1..n
	for j in 1..i-1
		k = i^j
		if k <= j and k + j > i
			ans += 1
		end
	end
end
puts ans