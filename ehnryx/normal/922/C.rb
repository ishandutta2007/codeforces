require 'set'

n, k = gets().split().map(&:to_i)

seen = [].to_set
shit = false
for i in 1..[k,1000].min
	r = n % i
	if seen.include? r
		shit = true
		break
	else
		seen.add(r)
	end
end

if shit
	puts "No"
else
	puts "Yes"
end